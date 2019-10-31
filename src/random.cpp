#include "random.h"



RandomNumbers::RandomNumbers(unsigned long int s)
{
	if(s ==0) {
		std::random_device rd;
		seed = rd();
	}
	else {
		seed = s;
	}
	rng = std::mt19937(seed);
}

void RandomNumbers::uniform_double(std::vector<double>& tableau, double lower, double upper) {
		std::uniform_real_distribution<> unifDistrib(lower, upper);
		for(auto& tab : tableau) tab = unifDistrib(rng);	
}
double RandomNumbers::uniform_double(double lower, double upper){
		std::uniform_real_distribution<> unifDistrib(lower, upper);
		return unifDistrib(rng);
}
void RandomNumbers::normal(std::vector<double>& tableau, double mean, double sd){
		std::normal_distribution<> normDistrib(mean, sd);
		for(auto& tab : tableau) tab = normDistrib(rng);
}
double RandomNumbers::normal(double mean, double sd){
	std::normal_distribution<> normDistrib(mean, sd);
	return normDistrib(rng);
}
void RandomNumbers::poisson(std::vector<int>& tableau, double mean){
	std::poisson_distribution<> poissonDistrib(mean);
	for(auto& tab : tableau) tab = poissonDistrib(rng);

}
int RandomNumbers::poisson(double mean){
	std::poisson_distribution<> poissonDistrib(mean);
	return poissonDistrib(rng);
}



