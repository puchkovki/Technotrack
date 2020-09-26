1. To build a project in current directory and to save it in folder `_build`:
```
cmake -H. -B_build
```
2. To build a project with tests in current directory and to save it in folder `_build`:
```
cmake -H. -B_build -DBUILD_TESTS=ON  
```
3. 
```
cmake --build _build 
```
4. To run tests:
```
_build/check
```
5. To run tests in details and save result into the `res/test.txt` file:
```
cmake --build _build --target test -- ARGS=--verbose > res/test.txt
```

