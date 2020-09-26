1. To build a project in current directory and to save it in folder `_build`:
```
cmake -H. -Bbuild
```
2. Compile CMakelists, 
Компиляции cnakelists, создание нужные папки и makefile
```
cmake -H. -Bbuild -DBUILD_TESTS=ON  
```
3. To build a project with tests in current directory and to save it in folder `_build`:
```
cmake --build build 
```
4. To run tests:
```
build/check
```
5. To run tests in details and save result into the `res/test.txt` file:
```
cmake --build build --target test -- ARGS=--verbose > res/test.txt
```

