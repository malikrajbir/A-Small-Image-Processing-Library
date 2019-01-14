/* Main program.
    Take all inputs from command line.
    Take actions accordingly
    */
#include <iostream>
#include <fstream>
#include <cstring>

#include "activation.h"
#include "pool.h"
#include "padding.h"
#include "convolution.h"
#include "IO.h"


using namespace std;

int main(int argc, char const *argv[]) {
    try {
        if(argc == 1)
            throw runtime_error("No function. Please enter a function.\n");
        /*-------------------------------------------------------------
        -------------------------------------------------------------*/
        if(argv[1][0] == 'c')
        /* conv or cross*/
        {
            if(argv[1][1] == 'o')
            /* conv */
            {
                if(!strcmp("conv", argv[1])) {
                    vector<vector<float>> matrix{};
                    try {
                        matrix = inputMatrix(argv[2]);
                    }
                    catch(...) {
                        throw runtime_error("Error with matrix file. Please check.\n");
                    }
                    vector<vector<float>> kernel{};
                    try {
                        kernel = inputMatrix(argv[3]);
                    }
                    catch(...) {
                        throw runtime_error("Error with kernel file. Please check.");
                    }
                    if(kernel.size() > matrix.size())
                        throw runtime_error("Invalid: Kernel size is greater than matrix size.");
                    if(argc == 4)
                    /* Output on command line*/
                    {
                        writeSquareMatrix(mapping(kernel, matrix, true));
                    }
                    else if (argc == 5)
                    /* Output in File*/
                    {
                        try {
                            ofstream out(argv[3]);
                            writeSquareMatrix(mapping(kernel, matrix, true), out);
                        }
                        catch(...) {
                            throw runtime_error("Error in writing. Please check.");
                        }
                    }
                    else
                        throw runtime_error("Command statement wrong. Please see documentation.\n");

                }


                else if(!strcmp("conv_pad", argv[1])) {
                    vector<vector<float>> matrix{};
                    try {
                        matrix = inputMatrix(argv[2]);
                    }
                    catch(...) {
                        throw runtime_error("Error with matrix file. Please check.\n");
                    }
                    vector<vector<float>> kernel{};
                    try {
                        kernel = inputMatrix(argv[3]);
                    }
                    catch(...) {
                        throw runtime_error("Error with kernel file. Please check.");
                    }
                    if(kernel.size() > matrix.size())
                        throw runtime_error("Invalid: Kernel size is greater than matrix size.");
                    if(argc == 4)
                    /* Output on command line*/
                    {
                        writeSquareMatrix(mapping(kernel, matrix, true, true));
                    }
                    else if (argc == 5)
                    /* Output in File*/
                    {
                        try {
                            ofstream out(argv[3]);
                            writeSquareMatrix(mapping(kernel, matrix, true, true), out);
                        }
                        catch(...) {
                            throw runtime_error("Error in writing. Please check.");
                        }
                    }
                    else
                        throw runtime_error("Command statement wrong. Please see documentation.\n");
                }


                else if(!strcmp("conv_mult", argv[1])) {
                    vector<vector<float>> matrix{};
                    try {
                        matrix = inputMatrix(argv[2]);
                    }
                    catch(...) {
                        throw runtime_error("Error with matrix file. Please check.\n");
                    }
                    vector<vector<float>> kernel{};
                    try {
                        kernel = inputMatrix(argv[3]);
                    }
                    catch(...) {
                        throw runtime_error("Error with kernel file. Please check.");
                    }
                    if(kernel.size() > matrix.size())
                        throw runtime_error("Invalid: Kernel size is greater than matrix size.");
                    if(argc == 4)
                    /* Output on command line*/
                    {
                        writeSquareMatrix(convolutionByMultiplication(kernel, matrix, true));
                    }
                    else if (argc == 5)
                    /* Output in File*/
                    {
                        try {
                            ofstream out(argv[3]);
                            writeSquareMatrix(convolutionByMultiplication(kernel, matrix, true), out);
                        }
                        catch(...) {
                            throw runtime_error("Error in writing. Please check.");
                        }
                    }
                    else
                        throw runtime_error("Command statement wrong. Please see documentation.\n");
                }


                else if(!strcmp("conv_mult_pad", argv[1])) {
                    vector<vector<float>> matrix{};
                    try {
                        matrix = inputMatrix(argv[2]);
                    }
                    catch(...) {
                        throw runtime_error("Error with matrix file. Please check.\n");
                    }
                    vector<vector<float>> kernel{};
                    try {
                        kernel = inputMatrix(argv[3]);
                    }
                    catch(...) {
                        throw runtime_error("Error with kernel file. Please check.");
                    }
                    if(kernel.size() > matrix.size())
                        throw runtime_error("Invalid: Kernel size is greater than matrix size.");
                    if(argc == 4)
                    /* Output on command line*/
                    {
                        writeSquareMatrix(convolutionByMultiplication(kernel, matrix, true, true));
                    }
                    else if (argc == 5)
                    /* Output in File*/
                    {
                        try {
                            ofstream out(argv[3]);
                            writeSquareMatrix(convolutionByMultiplication(kernel, matrix, true, true), out);
                        }
                        catch(...) {
                            throw runtime_error("Error in writing. Please check.");
                        }
                    }
                    else
                        throw runtime_error("Command statement wrong. Please see documentation.\n");
                }


                else
                    throw runtime_error("Invalid Function. Did you mean 'conv'?\n");
            }
            else if(argv[1][1] == 'r')
            /* cross */
            {

            }
            else
                throw runtime_error("Invalid Function. Did you mean 'conv' or 'cross'?\n");
        }
        /*-------------------------------------------------------------
        -------------------------------------------------------------*/
        else if(argv[1][0] == 'r')
        /*relu*/
        {
            if(strcmp("relu", argv[1]))
                throw runtime_error("Invalid Function. Did you mean 'relu'?\n");
            vector<vector<float>> matrix{};
            try {
                matrix = inputMatrix(argv[2]);
            }
            catch(...) {
                throw runtime_error("Error with matrix file. Please check.\n");
            }
            if(argc == 3)
            /* Output on command line*/
            {
                writeSquareMatrix(relu(matrix));
            }
            else if (argc == 4)
            /* Output in File*/
            {
                try {
                    ofstream out(argv[3]);
                    writeSquareMatrix(relu(matrix), out);
                }
                catch(...) {
                    throw runtime_error("Error in writing. Please check.");
                }
            }
            else
                throw runtime_error("Command statement wrong. Please see documentation.\n");
        }
        /*-------------------------------------------------------------
        -------------------------------------------------------------*/
        else if(argv[1][0] == 't')
        /*tanh*/
        {
            if(strcmp("tanh", argv[1]))
                throw runtime_error("Invalid Function. Did you mean 'tanh'?\n");
            vector<vector<float>> matrix{};
            try {
                matrix = inputMatrix(argv[2]);
            }
            catch(...) {
                throw runtime_error("Error with matrix file. Please check.\n");
            }
            if(argc == 3)
            /* Output on command line*/
            {
                writeSquareMatrix(tanh(matrix));
            }
            else if (argc == 4)
            /* Output in File*/
            {
                try {
                    ofstream out(argv[3]);
                    writeSquareMatrix(tanh(matrix), out);
                }
                catch(...) {
                    throw runtime_error("Error in writing. Please check.");
                }
            }
            else
                throw runtime_error("Command statement wrong. Please see documentation.\n");
        }
        /*-------------------------------------------------------------
        -------------------------------------------------------------*/
        else if(argv[1][0] == 's')
        /*softmax or sigmoid*/
        {
            if(argv[1][1] == 'o')
            /* softmax */
            {
                if(strcmp("softmax", argv[1]))
                    throw runtime_error("Invalid Function. Did you mean 'softmax'?\n");
                vector<float> vectr{};
                try {
                    vectr = inputVector(argv[2]);
                }
                catch(...) {
                    throw runtime_error("Error with vector file. Please check.");
                }
                if(argc == 3)
                /* Output on command line*/
                {
                    writeVector(softmax(vectr));
                }
                else if (argc == 4)
                /* Output in File*/
                {
                    try {
                        ofstream out(argv[3]);
                        writeVector(softmax(vectr), out);
                    }
                    catch(...) {
                        throw runtime_error("Error in writing. Please check.");
                    }
                }
                else
                    throw runtime_error("Command statement wrong. Please see documentation.\n");
            }
            else if(argv[1][1] == 'i')
            /* sigmoid */
            {
                if(strcmp("sigmoid", argv[1]))
                    throw runtime_error("Invalid Function. Did you mean 'sigmoid'?\n");
                vector<float> vectr{};
                try {
                    vectr = inputVector(argv[2]);
                }
                catch(...) {
                    throw runtime_error("Error with vector file. Please check.");
                }
                if(argc == 3)
                /* Output on command line*/
                {
                    writeVector(sigmoid(vectr));
                }
                else if (argc == 4)
                /* Output in File*/
                {
                    try {
                        ofstream out(argv[3]);
                        writeVector(sigmoid(vectr), out);
                    }
                    catch(...) {
                        throw runtime_error("Error in writing. Please check.");
                    }
                }
                else
                    throw runtime_error("Command statement wrong. Please see documentation.\n");
            }
            else
                throw runtime_error("Invalid Function. Did you mean 'sigmoid' or 'softmax'?\n");
        }
        /*-------------------------------------------------------------
        -------------------------------------------------------------*/
        else if(argv[1][0] == 'm')
        /* max_pool */
        {
            if(strcmp("max_pool", argv[1]))
                throw runtime_error("Invalid Function. Did you mean 'max_pool'?\n");
            vector<vector<float>> matrix{};
            try {
                matrix = inputMatrix(argv[2]);
            }
            catch(...) {
                throw runtime_error("Error with matrix file. Please check.\n");
            }
        }
        /*-------------------------------------------------------------
        -------------------------------------------------------------*/
        else if(argv[1][0] == 'a')
        /* avg_pool */
        {
            if(strcmp("avg_pool", argv[1]))
                throw runtime_error("Invalid Function. Did you mean 'avg_pool'?\n");
            vector<vector<float>> matrix{};
            try {
                matrix = inputMatrix(argv[2]);
            }
            catch(...) {
                throw runtime_error("Error with matrix file. Please check.\n");
            }
        }
        /*-------------------------------------------------------------
        -------------------------------------------------------------*/
        else
            throw runtime_error("Invalid Function\n");
    }
    catch(const exception& e) {
        cout << e.what();
    }
    return 0;
}