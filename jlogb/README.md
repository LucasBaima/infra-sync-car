# Sincronização do Metrô (sync_car)

Implementação 4 de Infraestrutura de Software (CESAR School).

Sincronização do embarque de passageiros em vagões usando pthreads
(um único mutex e duas variáveis de condição, sem busy wait).

Relatório: [jlogb.pdf](jlogb.pdf)

## Arquivos (pasta `jlogb/`)
- `sync_car.h`: struct station e protótipos das funções.
- `sync_car.c`: implementação de station_init, station_load_car,
  station_wait_for_car e station_on_board.
- `sync_car-runner.c`: teste fornecido pelo professor (não alterado).
- `Makefile`: compilação e limpeza.

## Compilar, executar e limpar
    cd jlogb
    make            # gera o executável sync_car
    ./sync_car      # saída esperada: Looks good!
    make clean      # remove o executável e os .o

## Teste de estresse (200 execuções)
    for i in $(seq 1 200); do ./sync_car > /dev/null || { echo "FALHOU na rodada $i"; break; }; done; echo "fim"

Resultado: 200 de 200 execuções com sucesso.

## Sistema operacional
Desenvolvido no Windows; compilado e testado no Linux Mint.
O runner usa APIs POSIX (alarm, SIGALRM, random), por isso não
compila nativamente no Windows.

## Observação
O único warning de compilação (parâmetro `foo` não usado) vem do
`sync_car-runner.c` do professor. O código do aluno compila sem warnings.