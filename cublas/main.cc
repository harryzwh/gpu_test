// An example

#include <iostream>
#include <vector>
#include "simulator.h"
#include "operator.h"
#include "utils.h"

int main(int argc, char* argv[]) {
	int M = 12288;
	int N = 9216;
	int K = 32768;
	int loop=1000;
	while (argc) {
		if (*argv[0] == '-') {
		switch (*(argv[0] + 1)) {
			case 'm':
			M = (int)atol(argv[0] + 2);
			break;
			case 'n':
			N = (int)atol(argv[0] + 2);
			break;
			case 'k':
			K = (int)atol(argv[0] + 2);
			break;
			case 'N':
			loop = (int)atol(argv[0] + 2);
			break;
			default:
			break;
			}
		}
		argc -= 1;
    	argv++;
	}

	std::vector<OpConfig> configVector;
	
	OpConfig matMulConfig;
	matMulConfig.opType = OpType::MATMUL;
	matMulConfig.args   = {
		/* M = */ M,
		/* N = */ N,
		/* K = */ K,
		/* transa = */ 0,
		/* transb = */ 0,
		/* tenser_op = */ 0,
		/* algo   = */ -1,
		/* dtype*/ DTYPE_HALF
	};

	configVector.push_back(matMulConfig);

	std::cout << "Test performence of Gemm\n";
	std::cout << "M=" << M << " N=" << N << " K=" << K << std::endl;
	Simulator* simu = new Simulator;
	simu->initOp(configVector);
	PfMap pfMap = simu->measureAllOp(1000);
	printf("Avg time: %F ms  TFLOPS: %F\n", pfMap[matMulConfig].getDurtime(), pfMap[matMulConfig].getTflops());
	simu->freeOp(); 
	delete simu;

	std::cout << "End of test\n";
	return 0;
}
