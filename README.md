# Arduino Line Tracer Car(sketch_sep28a.ino)

## 1. 개요
라인 트레이서 RC카란 부착된 적외선 센서가 인식할 수 있는 검정색 선을 따라 주행하는 자율이동 로봇이다.   라인 트레이서의 기본적인 원리는 바닥에 그려진 주행선을 적외선 센서로 검출하여 목적 위치까지 선을 따라 이동하는 것이다. 이 적외선 센서는 검정색과 하얀색으로만 검출할 수 있으며, 적외선 센서가 바닥으로 방출한 빛을 흡수하면 검은색으로 인식하고, 반사하면 흰색으로 인식하여 주행선을 따라 이동한다.


## 2. 구성 요소 및 원리
본 실험에서 사용된 라인 트레이서 RC카의 구성 요소는 다음과 같다.
우리 라인 트레이서RC카는 몸체 하단 부분에 왼쪽, 중앙, 오른쪽에 적외선 센서를 위치했다. 적외선 센서는 적외선을 송신하는 송신부와 적외선을 수신하는 수신부로 구성되는데, 검은색 면에서의 적외선을 흡수해서 LOW 신호를 출력하고 검은색 면이 감지되지 않으면 HIGH 신호를 출력한다. 이를 이용하여 라인 트레이서가 검은색 선의 가운데에 위치할 때는 양쪽 모터가 정방향 회전하여 직진한다.
 
 한편 검은색 선이 RC카의 왼쪽 부분으로 치우쳐져 있으면 오른쪽 적외선 센서가 검은색 선을 인식하지 못하기 때문에 왼쪽 모터는 정지, 오른쪽 모터는 회전함으로써 왼쪽으로 회전하게 된다. 오른쪽 방향으로의 회전 역시 원리는 같다. 라인 트레이서 센서는 거리가 가까운 물체만 감지가 가능하기 때문에 센서와 바닥 사이의 간격을 좁게 했다. 또한 센서의 감도는 가변저항으로 조절이 가능하기 때문에, 이를 이용하여 센서가 검은색 면을 인지할 수 있는 범위를 조절했다. 라인 트레이서 센서에 있는 3개의 핀은 각각 그라운드, 전원, 아두이노 핀에 연결하였는데, 오른쪽 센서는 아두이노 핀 A5, 가운데 센서는 A4, 왼쪽 센서는 A3에 각각 연결하였다. 
모터의 속도를 제어하고, 모터의 방향을 바꾸기 위해서 모터 드라이버를 사용했다. 모터드라이버는 작은 전류와 전압을 제어하는 프로세서와 큰 전류로 작동하는 모터 사이에 중재 역할을 하는 장치이다. 모터는 DC모터를 사용하였으며 DC모터는 전류가 흐르는 방향에 따라서 모터의 회전 방향을 바꿀 수 있다.  모터의 속도는 DC전압을 제어하면 속도를 바꿀 수 있다. 전압이 커지면 속도가 증가하고, 전압이 낮아지면 속도가 감소하지만 DC전압을 손쉽게 제어하기 힘들기 때문에 PWM 제어를 사용하여 모터의 속도를 제어하였다. PWM(Pulse Width Modulation)은 펄스의 폭을 제어하여 출력을 조절하는 방식입니다. PWM을 사용하면 디지털 출력으로 아날로그 회로의 제어가 가능하다. 배터리는 9V 배터리 2개를 사용하여 전원을 공급하였는데, 아두이노 우노에 5V를 공급하고 두 개의 모터에 4.5V씩 공급할 수 있도록 설계하였다.


## 3. Project Specification
### 3-1. Hardware
#### 회로도

![alt text](https://github.com/Junst/Arduino_Line_Tracer_Car/blob/master/pic/7%20linetracer_bb.png)

#### 아두이노 UNO 보드
![alt text](https://github.com/Junst/Arduino_Line_Tracer_Car/blob/master/pic/%EA%B7%B8%EB%A6%BC1.jpg)

물리적인 세계를 감지하고 제어할 수 있는 인터랙티브 객체들과 디지털 장치를 만들기 위한 도구이다. 컴퓨터에 입력된 코드를 아두이노 UNO 보드에 입력시켜 보드에 저장을 시킨 다음 주어진 코드대로 모터 드라이버가 실행하도록 하였다.

#### 브레드 보드
![alt text](https://github.com/Junst/Arduino_Line_Tracer_Car/blob/master/pic/%EA%B7%B8%EB%A6%BC3.jpg)

납땜 없이 단지 구멍에 부품 혹은 선을 꽂기만 서로가 연결되니 유용하게 사용할 수 있는 제품이다. 같은 줄에 부품들을 꽂으면 서로 연결되어 전기가 통하게 되지만 다른 줄에 꽂으면 전기가 흐르지 않는다. 따라서 저희는 이러한 부분을 개선하기 위해 여러 줄을 철사로 연결하여 전기가 흐르도록 하였다

#### 모터 드라이버 (L298N)
![alt text](https://github.com/Junst/Arduino_Line_Tracer_Car/blob/master/pic/%EA%B7%B8%EB%A6%BC4.jpg)

Arduino를 보조해주는 역할을 수행한다. 모터는 보통 Arduino와 같은 마이크로 컨트롤러가 허용하는 전류보다 전류를 많이 사용하기 때문에 추가적인 회로가 필요한데, 그 역할을 하는 것이 모터 드라이버이다. 

#### DC 모터
![alt text](https://github.com/Junst/Arduino_Line_Tracer_Car/blob/master/pic/%EA%B7%B8%EB%A6%BC5.jpg)

2개의 단자가 있으며, 단자에 +, -극을 연결하여 전원을 입력하면 모터가 작동한다. DC모터는 극이 없으며, 전원을 반대로 연결한 경우에는 반대로 회전하는 성질을 갖는다. 또한 입력되는 전원(전압)의 크기에 따라 회전수와 힘이 조절된다. 이때 전원과 회전 수 및 힘은 비례한다.


#### 적외선 센서 
![alt text](https://github.com/Junst/Arduino_Line_Tracer_Car/blob/master/pic/%EA%B7%B8%EB%A6%BC6.png) ![alt text](https://github.com/Junst/Arduino_Line_Tracer_Car/blob/master/pic/%EA%B7%B8%EB%A6%BC7.png)

라인 트레이서가 라인을 따라가는 원리는 검은색은 빛을 흡수하고 흰색은 빛을 반사하는 원리를 통해 적외선 센서를 이용하여 감지하게 되는 것이다. 이 때 라인트레이서 가운데에 있는 센서의 감도를 조절하여 라인을 쉽게 감지할 수 있도록 해주는 것이 중요하다.

### 3-2. Software
#### Arduino IDE(Sketch)
![alt text](https://github.com/Junst/Arduino_Line_Tracer_Car/blob/master/pic/ard.png)

아두이노 통합개발환경(Arduino IDE)은 편집기, 컴파일러, 업로더 등이 합쳐진 소프트웨어 환경이다. '아두이노 소프트웨어'라고도 불린다. 이와 더불어 기타 개발에 필요한 각종 옵션 및 라이브러리 관리를 할 수 있다. 아두이노 프로그램 실행 시, 개인용 컴퓨터와 시리얼 통신을 할 수 있는 가상 시리얼모니터를 제공한다. 보통 USB을 통해 업로드를 하므로 아두이노 보드는 USB를 UART 통신으로 바꾸는 방법이 제공되고, MCU가 실행할 때는 이 UART 통신을 이용하여 필요한 통신을 할 수 있다. 이렇게 되려면 아두이노의 MCU는 부트로더가 올라가 있어야 한다. 특히 아두이노 프로그램을 '스케치(Sketch)'라고 부른다.

#### Fritzing
![alt text](https://github.com/Junst/Arduino_Line_Tracer_Car/blob/master/pic/fri.png)

Fritzing은 전자 하드웨어 설계를 위한 아마추어 또는 비전문가를 위한 EDA CAD 소프트웨어를 개발하고 프로토 타입을 실험하는 것에서부터 제작용 회로를 만드는 것까지 폭넓게 사용할 수 있는 디자이너와 아티스트를 지원하기위한 오픈 소스 프로젝트이다. 포츠담 대학교 응용과학부에서 개발되었다.

# Arduino Bluetooth Car
#### Fritzing
![image](https://github.com/Junst/Arduino_Car/blob/master/BluetoothRCcar/Bluetoothrc_bb.png)

# Arduino Ultra Sonic Car

