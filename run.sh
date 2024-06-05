pip install -r requirements.txt
mkdir build
cd build
cmake ..
make
python3 ../main.py & ./main