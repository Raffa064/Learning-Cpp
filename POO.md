# Guia rápido de POO

## O q é?
POO é uma sigla para Programação Orientada a objetos, que nada mais é 
do que um paradigma no qual uma linguagem se baseia no uso de objetos.

O que são classes e objetos?
Uma boa analogia para classes e objetos é que a classe é como se fosse
uma espécie, e o objeto um individuo. Sendo assim, uma classe define
como um objeto dever ser, desde suas características ate seus 
comportamentos.

Na programação, as características se dão por meio de variáveis,
chamadas de atributos ou fields (q significa campos), e os e 
comportamentos são definidos por funções, que quando declaradas
em classes passam a se chamar métodos.

Voltando a analogia, se você considerar Porco como uma classe,
você pode ter nela cor, peso, altura, e raça como atributos, e, por
exemplo, rolar na lama como comportamento que poderia ser um método
chamado rolarNaLama().

## Herança
Entendido isso, podemos avançar um pouco mais, chegando ao conceito
de herança, que nada mais é do que criar classes que herdam 
características e comportamentos de outra classe.
Uma possível analogia para isso, é quando um filho nasce parecido
com seus pais, tendo assim, herdado tais características.

Um exemplo de uso da herança, esta no arquivo src/tests/classes.cpp,
onde eu criei uma classe Fruit (fruta) que define algumas 
características que uma fruta pode ter, como acidez e doçura, que
foram sobrescritas/alteradas em suas classes filhas (Maça e Limão)
para adequar a suas especificações.
Observe, que os métodos como getAcidity() so foram implementados na 
classe Fruit, ja que seu comportamento é o mesmo em todos os casos,
ao contrario do método getName() que é re-implementado tanto para
Maça quanto para Limão para retornar seus respectivos nomes.

## Polimorfismo
O termo polimorfismo se refere a possibilidade de uma classe filha ser
referenciada pela classe pai, o que pode parecer estranho mas, essa
analogia talvez deixe um pouco mais claro:
Se para umm certa consulta você precisa de um médico, então qualquer
médico pode realizar a consulta, com tanto que seja um médico.
Mas para uma cirurgia, não pode ser qualquer médico, tem que ser um
cirurgião.
Atente-se ao fato de que em ambos os casos se trata de um médico,
portanto, Médico é classe, Cirurgião é a sub-classe, ou classe filha.
Nem todo médico é cirurgião, mas todo cirurgião é um médico.
Tendo isso em mente, uma consulta tem como parâmetro um médico,
que pode ser qualquer médico a princípio, podendo aceitar até mesmo
um cirurgião se necessário. Mas uma cirurgia é somente para 
cirurgiões, então um médico qualquer não pode realiza-la.

Um exemplo disso em código seria:

void consulta(Medico m) { .... }

void cirurgia(Cirurgião c) { .... }

int main() {
  Pediatra p = ..... ;
  Oftalmologista o = ....;
  Cirurgião c = ....;

  consulta(p); //Ok, um pediatra é um médico
  consulta(o); //Ok, um oftalmologista é um médico
  consulta(c); //Ok, um cirurgião é um médico

  cirurgia(p); //Erro, um pediatra não é um cirurgião  
  cirurgia(o); //Erro, um oftalmologista não é um cirurgião  
  cirurgia(p); //Ok, um cirurgião é um cirurgião  
}

OBS: Nesse exemplo, são os erros em tempo de compilação, portanto
os erros vão aparecer assim q vc tentar compilar.

OBS2: Para esse tipo de código funcionar (para convertendo classe
filha em classe pai) a classe tem que declarar a "classe base"
como publica, exemplo:

class A { ... }

class B : public A { ... }