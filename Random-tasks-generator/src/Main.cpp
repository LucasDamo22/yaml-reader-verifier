#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>


/// @brief Function responsible for generating random numbers, obeying the rules of maximum and minimum value, and making sure, none of the values is equal to 0.
/// @param min 
/// @param max 
/// @return The random number generated within the scope.
float random(int min, int max) {
  if (min == 1 && max == 1) max += 1;

  return (rand() % (min - max)) + min;
}

int main(int argc, char **argv) {
  
  // Initializes the pseudo-random number generator with a different
  // seed at every program call
  srand(time(NULL));

  int UTILIZACAO_ALVO;
  
  // Loop responsible for generating the files with random tasks within the range
  // requested by the user.
  for(int z=atoi(argv[1]); z<atoi(argv[2]); z++){
    
    // The current cpu utilization target
    UTILIZACAO_ALVO = z;
    
    // Set the minimal number of possibles portions to 10% of the cpu utilization target
    int min_parcelas = (UTILIZACAO_ALVO / 10) + 1;
    // Set the maximal number of possibles portions to 20% of the cpu utilization target
    int max_parcelas = (UTILIZACAO_ALVO / 5) + 1;

    
    // Defines a number of portions between the minimal amount and the maximum amount
    int num_parcelas = random(min_parcelas, max_parcelas);

    // The amount of CPU available is given by UTILIZACAO_ALVO. While we dont 
    // hit that utilization target, we keep generating portions.
    int utilizacao_atual = 0;

    int min_valor_parcela, max_valor_parcela;
    float parcelas[num_parcelas];
    float parcelasSuperiores[num_parcelas];

    for (int i = 0; i < num_parcelas; i++) {
      // portion will have at least 5% of the ramaining utilization (minimum value = 1)
      min_valor_parcela = ((UTILIZACAO_ALVO - utilizacao_atual) / 20) + 1;

      // portion will have at least 20% of the ramaining utilization (minimum value = 1)
      max_valor_parcela = ((UTILIZACAO_ALVO - utilizacao_atual) / 5) + 1;

      int parcela = random(min_valor_parcela, max_valor_parcela);
      utilizacao_atual += parcela;

      parcelas[i] = parcela;
    }
    //adding the missing amount on the last portion
    
    parcelas[num_parcelas - 1] = parcelas[num_parcelas - 1] +(UTILIZACAO_ALVO -utilizacao_atual);  

    // Transforming the portions in fractions that equals to utilization coefficient of each task
    // then placing it on an array of numerators called "parcelasSuperiores"
    for (int i = 0; i < num_parcelas; i++) {
      float aux = parcelas[i];
      parcelas[i] = parcelas[i] * 100;
      parcelasSuperiores[i] = (aux * UTILIZACAO_ALVO) / num_parcelas;
    }

    // Emitting the tasks to the yaml file
    std::ofstream arqOutYaml;

    std::string filename;

    filename = "./Cpu-usage-calculator/data/" + std::to_string(z) + ".yaml";
    std::cout << filename << std::endl;
    arqOutYaml.open(filename, std::ios::out);
    if (!arqOutYaml.is_open()) {
      std::cout << "erro na geração do arquivo";
      return 1;
    }
    arqOutYaml << "Processos:" << std::endl;
    for (int i = 0; i < num_parcelas; i++) {
      arqOutYaml << "  processo" << i + 1 << ":"
                << " [" << parcelasSuperiores[i] << ", " << parcelas[i] << "]"
                << std::endl;
    }
    arqOutYaml.close();
  }

  return 0;
}
