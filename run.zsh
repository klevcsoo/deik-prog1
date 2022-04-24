#!/bin/zsh
set -e
set -o localoptions -o localtraps

outfile_dir=${1%/*}
outfile_name=${${1##*/}%%.*}
outfile_extension=${1##*.}
valid_extensions=( "cpp" "cc" "c++" )

# Ha nem megfelelő a fájltípus, hibával kilépünk
if [[ ! ${valid_extensions[(ie)$outfile_extension]} -le ${#valid_extensions} ]]; then
  echo "script: \e[31;1merror:\e[0m Extension must be .cpp"
  exit 1
fi

# Hozzuk létre az output fájl bin mappáját, ha még nincs
mkdir -p ./bin/${outfile_dir}

# Fordítsuk le és futtassuk
if [[ `uname` == 'Darwin' ]]; then # macOS-en vagyunk
  g++ -std=c++17 -lstdc++ ${1} -o ./bin/${outfile_dir}/${outfile_name}
elif [[ `uname` == 'Linux' ]]; then # Linux-on vagyunk
  g++ ${1} include/Graph.cpp include/Lines_window.cpp include/Window.cpp include/GUI.cpp include/Simple_window.cpp -o ./bin/${outfile_dir}/${outfile_name} -I./include `fltk-config --ldflags --use-images` -std=c++11
else
  echo "script: \e[31;1merror:\e[0m OS not supported"
  exit 1
fi

./bin/${outfile_dir}/${outfile_name}
