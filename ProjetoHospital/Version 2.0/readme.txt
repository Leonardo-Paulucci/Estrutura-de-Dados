ANOTAÇÕES DE USO DO PROJETO HOSPITAL

• Estrutura de arquivos:

ProjetoHospital/Version1.0
-main.c
-pilha.c
-fila_linear.c
-fila_circular.c
-paciente.h
-hospital.exe
-readme.txt

• Códigos para executar no terminal do VS Code:

1 - comando para compilar o programa na hora (recriar o .exe):

gcc main.c pilha.c fila_circular.c fila_prioridade.c -o hospital

2 - comando para deixar o texto no terminal em UTF-8:

chcp 65001

3 - comando para executar o programa (.exe):
cd "Version 2.0"
./hospital.exe

4 - Instalar o Cppcheck
https://cppcheck.sourceforge.io/?utm_source=chatgpt.com

Rodar análise: 
cppcheck --enable=all *.c
cppcheck --enable=all *.c > relatorio2.txt 2>&1

5 - Analise de Desempenho 
gcc analise_desempenho.c pilha.c fila_circular.c fila_prioridade.c -o analise
.\analise.exe

• Agora é só operar o programa através do menu gerado no terminal do VS Code. 
