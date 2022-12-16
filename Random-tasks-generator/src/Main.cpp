#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>



float random(int min, int max) {
  if (min == 1 && max == 1) max += 1;

  return (rand() % (min - max)) + min;
}

int main(int argc, char **argv) {
  // initializa o gerador de números pseudo-aleatórios com uma semente
  // diferente a cada inicialização
  srand(time(NULL));

  int UTILIZACAO_ALVO;
  std::cout<<atoi(argv[1])<<std::endl;
  std::cout<<atoi(argv[2])<<std::endl;
  for(int z=atoi(argv[1]);z<atoi(argv[2]);z++){
  UTILIZACAO_ALVO = z;
  //UTILIZACAO_ALVO = utilizacao;

  int min_parcelas = (UTILIZACAO_ALVO / 10) + 1;
  int max_parcelas = (UTILIZACAO_ALVO / 5) + 1;

  // std::cout << "min:" << min_parcelas << " max:" << max_parcelas <<
  // std::endl;

  // gera um número de parcelas entre min_parcelas e max_parcelas
  int num_parcelas = random(min_parcelas, max_parcelas);

  // o montante de CPU disponível é dado por UTILIZACAO_ALVO. Enquanto não
  // atingirmos essa utilização, geramos novas parcelas
  int utilizacao_atual = 0;

  int min_valor_parcela, max_valor_parcela;
  float parcelas[num_parcelas];
  float parcelasSuperiores[num_parcelas];

  for (int i = 0; i < num_parcelas; i++) {
    // parcela terá no mínimo 5% da utilizacao faltante (valor mínimo = 1)
    min_valor_parcela = ((UTILIZACAO_ALVO - utilizacao_atual) / 20) + 1;

    // parcela terá no mínimo 20% da utilização faltante (valor mínimo = 1)
    max_valor_parcela = ((UTILIZACAO_ALVO - utilizacao_atual) / 5) + 1;

    int parcela = random(min_valor_parcela, max_valor_parcela);
    utilizacao_atual += parcela;

    parcelas[i] = parcela;
  }

  parcelas[num_parcelas - 1] =
      parcelas[num_parcelas - 1] +
      (UTILIZACAO_ALVO -
       utilizacao_atual);  // adicionando o que falta na ultima parcela

  //**********Transformando as parcelas em frações que somem o coeficiente e
  // colocando em um array de numeradores chamado de "parcelasSuperiores"
  for (int i = 0; i < num_parcelas; i++) {
    float aux = parcelas[i];
    parcelas[i] = parcelas[i] * 100;
    parcelasSuperiores[i] = (aux * UTILIZACAO_ALVO) / num_parcelas;
  }

  //**********Mandando as parcelas para o arquivo yaml
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
