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

# Gyűjtsük össze az argomentumokat
args=""
for a; do
    args+="$a "
done

# Fordítsuk le és futtassuk
local_header_dir="/Users/klevcsoo/GitHub/deik-prog1/include"
fltk_header_dir="/opt/homebrew/Cellar/fltk/1.3.8/include"
g++ ${1} -std=c++17 -lstdc++ -I${local_header_dir} -I${fltk_header_dir} -I$(fltk-config --libs) -o ./bin/${outfile_dir}/${outfile_name}
./bin/${outfile_dir}/${outfile_name} $args
