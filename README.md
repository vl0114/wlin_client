# WLib

## 멤버
20185138 신영수

## 소개
리눅스의 시스템 정보를 온라인으로 볼 수 있는 프로젝트 입니다.<br>
- cpu 상태와 정보
- ram 상태와 정보
- 프로세스 상태
- 프로세스 제어

## 결과물
```
wlin_client
setting.json
```

## 사용법
setting.json에 연결할 서버의 ip와 포트, 서버에 표시될 이름을 입력하고<br>
wlin_client를 실행하면 됩니다.<br>


## 빌드
cmake를 사용하여 빌드합니다.
```
$ cmake CMakeLists.txt
$ make
```
요구
- boost
- <standard c++ 17>을 지원하는 컴파일러
  * gcc-8 이상
  * clang-8 이상  (*)
  * ...
- cmake 3.10.2 이상