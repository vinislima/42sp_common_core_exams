#!/bin/bash
# Uso: bash test.sh   (dentro da pasta life)

cd "$(dirname "$0")" || exit 1
cc -Wall -Wextra -Werror life.c -o life_test || exit 1
ok=0
ko=0

# t <entrada> <argumentos> <saida esperada (com $ no fim de cada linha, como cat -e)>
t()
{
	got=$(printf '%s' "$1" | ./life_test $2 | cat -e)
	exp=$(printf "$3")
	if [ "$got" = "$exp" ]; then
		ok=$((ok + 1))
	else
		ko=$((ko + 1))
		echo "KO: '$1' | ./life $2"
		echo "--- esperado:"; echo "$exp"
		echo "--- obtido:"; echo "$got"
	fi
}

# erro de argumentos: retorno 1 e nenhuma saida
e()
{
	got=$(printf 'x' | ./life_test $1)
	ret=$?
	if [ -z "$got" ] && [ $ret -eq 1 ]; then
		ok=$((ok + 1))
	else
		ko=$((ko + 1))
		echo "KO: argumentos [$1] (ret=$ret, saida='$got')"
	fi
}

# exemplos do enunciado (o echo adiciona \n, que e um comando invalido)
t $'sdxddssaaww\n' "5 5 0" '     $\n 000 $\n 0 0 $\n 000 $\n     $'
t $'sdxssdswdxdddxsaddawxwdxwaa\n' "10 6 0" '          $\n 0   000  $\n 0     0  $\n 000  0   $\n  0  000  $\n          $'
t $'dxss\n' "3 3 0" ' 0 $\n 0 $\n 0 $'
t $'dxss\n' "3 3 1" '   $\n000$\n   $'
t $'dxss\n' "3 3 2" ' 0 $\n 0 $\n 0 $'

# desenho
t "" "3 3 0" '   $\n   $\n   $'                         # entrada vazia
t "xaaawwwddddd" "3 2 0" '000$\n   $'                  # caneta nao sai do tabuleiro
t "x?d1d" "4 1 0" '000 $'                              # comandos invalidos ignorados
t "xddxdd" "5 1 0" '000  $'                            # levantar a caneta para de desenhar
t "xdxsxsxaxw" "3 3 0" '00 $\n00 $\n00 $'              # liga/desliga varias vezes

# simulacao
t "xdsa" "4 4 5" '00  $\n00  $\n    $\n    $'          # bloco: estavel
t "xdxsxsxaxw" "3 3 1" '00 $\n  0$\n00 $'
t "dxxdsxxsxaax" "6 6 0" ' 0    $\n  0   $\n000   $\n      $\n      $\n      $'
t "dxxdsxxsxaax" "6 6 4" '      $\n  0   $\n   0  $\n 000  $\n      $\n      $'   # glider anda 1 casa
t "dxxdsxxsxaax" "6 6 40" '      $\n      $\n      $\n      $\n    00$\n    00$'  # glider vira bloco na borda

# argumentos invalidos
e ""
e "5"
e "5 5"
e "5 5 1 extra"
e "0 5 1"
e "5 0 1"
e "5 5 -1"
e "abc 5 1"
e "100000 100000 0"

rm -f life_test
echo "OK: $ok  KO: $ko"
[ $ko -eq 0 ]
