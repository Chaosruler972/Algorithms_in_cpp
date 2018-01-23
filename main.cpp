


#include "self_implentations/matrix/main.h"


/**
 * this software will compute matrix multipication with N threads
 * @author Chaosruler972
 * @return upon success 0, else return failure code for GCC
 */

int main()
{
    auto tests = std::vector<test_configuration_unit>();

    /**
     * Test adding mechanism
     * tests.emplace_back(int MATRIX SIZE ,unsigned int AMOUNT OF THREADS );
     * to add into test
     * data should be in format of
     * mat -> matrices size (checked to be absolut, can't be 0)
     * threads -> amount of threads
     * @author Chaosruler972
     * MATRIX SIZE , THREADS!
     */

    /**
     * Reguler tests... 1000 on 1000, 1 thread to 8 threads
     * @author Chaosruler972
     */
    tests.emplace_back(1000,1);
    tests.emplace_back(1000,2);
    tests.emplace_back(1000,3);
    tests.emplace_back(1000,4);
    tests.emplace_back(1000,5);
    tests.emplace_back(1000,6);
    tests.emplace_back(1000,7);
    tests.emplace_back(1000,8);

    /**
     * Extreme tests, 100 to 400 threads
     * @author Chaosruler972
     */
    tests.emplace_back(1000,100);
    tests.emplace_back(1000,200);
    tests.emplace_back(1000,300);
    tests.emplace_back(1000,400);

    /**
     * Super extreme test, 1000 and 1500 threads
     * @author Chaosruler972
     */
    tests.emplace_back(1000,1000);
    tests.emplace_back(1000,1500);

    /**
     * Discpline test, 5000 threads
     * @author Chaosruler972
     */
    tests.emplace_back(1000,5000);


    for(auto configuration: tests)
    {
        /**
         * to mark some lines between tests
         * @author Chaosruler972
         */
        std::cout << std::endl << std::endl;


        std::cout << " Running test for configuration " <<
                  " matrices size " << configuration.MAX_MAT_SIZE << " And amount of threads is "
                  << ((configuration.N_THREADS==0 ) ? (unsigned int) omp_get_num_procs() : configuration.N_THREADS)
                << std::endl;
        test(configuration.N_THREADS,configuration.MAX_MAT_SIZE);


        /**
         * Wait a while after computation for threadding mechanism to settle down
         * and handling to be done
         * maximized for 10 seconds to increase global affect
         * @author Chaosruler972
         */
        std::cout << std::endl << "Testing is done." << std::endl;
        if(configuration != tests.back() )
        {
             std::cout << "Waiting " << TIME_TO_WAIT << " seconds after test finish before doing the next test..";
            std::this_thread::sleep_for(std::chrono::milliseconds(TIME_TO_WAIT*TO_MILLISECONDS));
            std::cout << std::endl << "Waiting is done, moving to next test" << std::endl;
        }
    }

    return 0;
}






/**
 * The actual testing
 * @param MAX_MAT_SIZE the matrix dimension (being N on N)
 * @param N_THREADS the amount of threads, 0 for default (amount of threads on CPU)
 * @author Chaosruler972
 */
void test(unsigned int N_THREADS, int MAX_MAT_SIZE)
{

    /**
    * Inspection cancelation for IDE and compiler
    * @author Chaosruler972
    */
    #pragma clang diagnostic push
    #pragma ide diagnostic ignored "OCDFAInspection"


    /**
     * Matrix initation
     * @author Chaosruler972
     */
    matrix m1(MAX_MAT_SIZE);
    matrix m2(MAX_MAT_SIZE);

    m1.set_threads(N_THREADS);
    m2.set_threads(N_THREADS);


    /**
     * Randomizing matrixes
     * @author Chaosruler972
     */

    m1.randomize();
    m2.randomize();

    /**
     * Timer and operation initation
     * @author Chaosruler972
     */
    auto t1 = high_resolution_clock::now();
    m1*m2;
    auto t2 = high_resolution_clock::now();
    auto diff = duration_cast<duration<double>>(t2 - t1);

    /**
     * Printing
     * @author Chaosruler972
     */
    std::cout << " Took " << diff.count() << " seconds to compute" << std::endl;

     /**
     * End of inspection cancellation, stops here, therefore won't reach out of library access
     * @author Chaosruler972
     */
    #pragma clang diagnostic pop
}

