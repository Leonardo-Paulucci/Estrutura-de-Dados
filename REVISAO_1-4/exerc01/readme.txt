Exercício 1 - Sistema de Atendimento de Clínica.
Uma clínica médica precisa de um sistema simples para organizar pacientes.

Estrutura do Projeto:
Clinica/
fila.c
fila.h
lista.c
lista.h
main.c
pilha.c
pilha.h

Comando para compilar no terminal:
gcc main.c fila.c pilha.c lista.c -o clinica

Comando para executar:
./clinica

Perguntas: 
1. Por que fila é ideal para recepção?
A fila é ideal para recepção porque funciona no modelo FIFO 
(First In, First Out), ou seja, o primeiro paciente que entra é o primeiro a ser atendido.
Isso garante organização e ordem de chegada no atendimento da clínica.

2. Por que pilha serve para desfazer ações?
A pilha é adequada para desfazer ações porque utiliza o modelo LIFO 
(Last In, First Out), onde o último elemento inserido é o primeiro a ser removido. 
Assim, ao desfazer um atendimento, o sistema remove o registro mais recente, simulando corretamente a operação de “desfazer”.

3. Por que lista encadeada é melhor que vetor para cadastros dinâmicos?
A lista encadeada é melhor que o vetor para cadastros dinâmicos porque permite inserir e remover pacientes facilmente sem precisar reorganizar todos os elementos da estrutura. Além disso, a lista utiliza memória dinamicamente, diferente do vetor que possui tamanho fixo.