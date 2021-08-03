source /d/packet/em/emsdk/emsdk_env.sh
#emsdk activate 2.0.10
cp ../data.0 ./
emcmake cmake ..
make -j 16
python -m http.server
