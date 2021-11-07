# SMSWH_Team31_QuadNP
**2021 Sookmyung Software Hackathon**

![KakaoTalk_20211107_235833050](https://user-images.githubusercontent.com/69629703/140650300-83ff9533-f72f-440c-88c8-1316ab1eaa6f.jpg)

### Development Environmental
Ubuntu 18.04 LTS ROS melodic
installed open package
1) rosserial
2) ublox_gps (GPS : ZED-C099 driver)
3) gps_common (coordinate : wgs -> utm)


## 🔶서비스 개요

***"마.피.아 : 마침내 피할 수 없는 아날로그 in the d1g1tal"***
 4차 산업 혁명의 도래와 코로나19로 일상의 모든 것들이 점차 디지털화 되고 있다. 
학창 시절에 형형색색 볼펜을 이용해 공책에 필기하던 것도, 누군가의 생일이라 손편지를 쓰는 것도 이제는 아이패드 필기, 카카오톡 축하 메시지 등으로 대체가 되고 있다. 
사실, 아이패드 필기, SNS 속 축하 메시지들은 끝이 없는 공간을 가진 데이터베이스에 저장된,
고작 몇 byte짜리 데이터 쪼가리에 불과하다.  
그래서 Quad NP는 아날로그 감성을 되돌리고자, 마침내 피할 수 없는 디지털로부터 바람을 쐴 수 있는 공간: ***"마.피.아 : 마침내 피할 수 없는 아날로그 in the d1g1tal"*** 프로젝트를 제안한다. 

 코로나19를 겪으며 학우들과의 소통이 부재한 요즘, 어떻게 하면 다시 일상으로 돌아가 서로의 따뜻한 감정을 나눌 수 있을까? 

 이 프로젝트의 RC Car가  가지는 의미 2가지는 다음과 같다.

🚖 Radio Controlled Car

📻 Radio Communication Car

 첫 번째로, 저희 RC Car는 무선 조종 차량으로서, 장소에 국한되지 않고 무선으로 달릴 수 있는 차량 플랫폼을 의미한다. 두 번째는, 라디오에서 사연을 읽어주듯, 저희 RC Car는 실내외에서 학우들 사이를 주행하며 편지를 받아 사회자에 전달한다.

 우리의 로봇 차량 플랫폼인 포피스(Poffice)가 여러분들의 감정을 전달하러 갑니다! 


## 🔶서비스 목적

 🎁 본 서비스 ***마.피.아 : 마침내 피할 수 없는 아날로그 in the d1g1tal*** 는 학교 축제와 같은 행사에서 **팝업성 이벤트**로 활용할 수 있다. 이때, 포피스는 학우들의 아날로그 감성을 소환시키고, 서로의 감정을 공유하는 아이템이 될 수 있다.

 행사 날, 포피스의 등장을 예고하고, 1시간 가량의 러닝 타임동안 학우들 사이를 움직이며 학우들과 상호작용하면서 귀여움과 아날로그 감성을 불러일으킨다. 학우들은 본인이 하고 싶었던 진솔한 이야기와 학우들과 공유하고 싶었던 진심을 담은 편지를 포피스에게 실어보낸다. 

 학우들의 편지를 가득 담은 포피스는 사회자에게 도착하고, 사회자는 포피스에 담긴 편지를 읽는다. 포피스가 나른, 각기 다른 사연을 담은 편지들은  불확실한 미래에 대한 걱정과 코로나19로 인한 서로의 짙은 그리움을 느끼는 학우들을 자연스레 연결해주는 매개체가 될 수 있다. 이를 통해 우리의 인연, 숙명, 운명을 느낄 수 있다.


## 🔶핵심 기술 및 주요 기능

### 핵심기술

- 경로 추종
    - GPS C099-F9P
        - size : 17.00mm x 22.0mm
        - 통신 : RTK
        - Update Speed : 최대 20Hz
        - 속도 정밀도 : 0.05m/s
        - 거리 정확도 : 1~3cm
        - 원리 : 최소 3개 위성을 사용한 삼각 측량법
        
        ![Untitled (20)](https://user-images.githubusercontent.com/69629703/140632743-77b128d8-11e9-4b87-9b5e-a0ba9615eac7.png)

        
    - RTK (Real Time Kinetmatic)
        
         실시간 운동학적 포지셔닝. 위성 네비게이션 시스템의 일반적인 오류를 수정합니다. GNSS 네트워크 방식으로 계산한 RTK 보정신호를 사용자 인근에 배치된 다수의 기준국들로부터 받아 종합적으로 활용하여 요청자 위치에 적합한 신호를 계산하는 방식으로 좌표를 출력함. 특히 위 서비스에서 사용하는  VRS(Virtual Reference System)방식은 요청자 GPS로부터 자신의 위치를 받아 해당 지점에 마치 GNSS 위성기준점이 있는 것과 같은 유사한 GNSS 관측 데이터를 생성하여 전달하기 때문에 오차범위 1cm 내의 정밀 좌표를 획득할 수 있음.
        
        ![Untitled (21)](https://user-images.githubusercontent.com/69629703/140632746-8010a1f6-2b62-4824-aa71-b61d983b2bcb.png)
        
- 차량 제어
    - 제어알고리즘 - Pure Pursuit
        
        차량의 현재 위치에서 목표점까지 이동하기 위한 곡률을 계산해 차량 조향값을 출력해 작동하는 경로 추종 알고리즘. 차량의 일정 거리 앞에 위치한 경로상의 목표점(이하 Lookahead Point)을 선택하는 것이다. 
        
        전륜조향각(δ, 사용하는 차량은 전륜구동차량으로 전륜조향각에 대해서만 다룸)에 대한 모델링은 차량동역학 bicycle model을 따르며, 다음과 같이 차량의 전륜조향각(δ)를 구할 수 있다. 구체적인 Bicycle Model은 아래의 그림과 같다.
        
        <img src="https://user-images.githubusercontent.com/69629703/140632510-5fe1d2c4-2673-4422-8465-d9f79881fbb9.png" width="430" height="120"/> 

        
        L : 차량 축간 거리
        R : 후륜에서 목표지점까지의 곡률 반경(L에 비해 R이 큼)
        
        <img src="https://user-images.githubusercontent.com/69629703/140632551-f1171a39-9346-45c3-930f-24662f604347.png" width="600" height="500"/>  
        
       
        
        Lookahead Point 를 선택하기 위해 필요한 Lookahead Distance(전방 주시 예견거리, 이하 Ld)를 통해 전륜조향각(δ)를 계산할 수 있다. Ld가 짧으면 진동이 발생하며, 길면 Cut-Corner(코너에서 예정경로보다 빨리 코너링을 함) 현상이 발생한다. 본 서비스에서는 저속으로 이동하기 때문에 최대속력과 최소속력의 차이가 적으므로 고정 Ld값을 사용한다.
        
        <img src="https://user-images.githubusercontent.com/69629703/140632649-37e61015-a265-4934-83a7-115d62a7e31d.png" width="700" height="600"/> 
        
        차량축간거리 L은 0.35m로 R을 구하여 전륜조향각(δ)를 구한다. 
        
        ![image](https://user-images.githubusercontent.com/69629703/140632715-d607067f-8780-45a2-b914-9b173ccdea9f.png)
        
        
    - PCA9685
        
        16채널 12비트 PWM 제어 모듈. 본 서비스에서는 PCA9685를 아두이노에 연결하여 각각 Servo모터와 ESC 모터를 구동하는데 사용한다. 
        

### 주요기능

**"센서 프로그래밍에 기반한 차량 플랫폼 제어"** 

- **차량이 돌아다닐 위치에 대한 waypoint를 취득한 다음, RTK GPS로부터 차량의 현재 위치와 waypoint 속 내가 가야 하는 점에 대한 차이를 구하며 주행**한다.
- 편지 작성자가 직접 사연을 제보하러 이동할 필요 없이 교내를 돌아다니는 차량 포피스(Poffice) 위에 설치된 간이 우체통에 제보할 수 있도록 한다. 포피스의 원활한 GPS 수신을 위해 교내 건물들의 주 출입구를 중심으로 돌아다니며 안전과 편의성을 위해 느린 속도로 주행하여 편지를 모으도록 한다.
- 차량에 올려진 우체통 속 편지들은 목적지인 축제 부스로 가서 모아지고, 사회자가 라디오 사연을 뽑듯이 편지 속 내용을 읽어 공유가 가능할 수 있도록 한다.


## 🔶기대 효과

 본 서비스인 ***마.피.아 : 마침내 피할 수 없는 아날로그 in the d1g1tal*** 은 참여자들을 대상으로 생각하지 못했던 이벤트를 선물한다. 기존에 사용자가 직접 사연을 편지나 메일로 보내는 방식에서 벗어나 ***직접 찾아가는 포피스 차량***을 통해 신선함을 줄 수 있다. 이는 **디지털 휴머니티 대학**으로서의 이미지를 굳건히 하는데 도움을 줄 것이다. 또한 인공지능, 자율주행의 상용화로 '인공지능이 인간을 대체할 수 있을 것이다.'는 부정적인 시각 대신, 사람간의 관계를 더 긴밀하게 이어주는 매개체로 느낄 수 있게 한다.

 포피스는 라디오 사연 편지의 단발성 이벤트를 넘어 향후 장기적인 사용으로 전환하여 편지 교환하는 펜팔과 같은 시스템으로 그 활용을 확장할 수 있을 것이다. 그에 대한 구체적인 시나리오는 다음과 같다. 첫 사용시 랜덤으로 상대방을 지정하여 펜팔을 매칭하여 펜팔이 끊기지 않는 한 매칭된 상대방은 계속 이어지게 되어 아날로그 감성을 지속적으로 유지하여 학우들 간의 연결을 보다 더 끈끈이 맺을 수 있도록 한다. 구체적인 SW시스템은 현재 개발을 진행한 gps waypoint 기반의 추종에 더하여 원활한 실내 이동을 위해 라인 트랙킹, 혹은 SLAM(Simultaneous Localization and Mapping; 동시적 위치추정 및 지도작성)을 진행하여 사용자 간의 편지 교환이 가능하도록 한다. 이 때 사용자의 위치는 어플리케이션을 통해 받도록 한다.
 
 또한 서비스 ***마.피.아***  뿐만 아니라 포피스 플랫폼은 새로운 서비스로의 확장 가능성을 제시한다. 편지를 옮기는 것에서 더 나아가 스노우 카페 커피 배달 혹은 일정 크기 이하의 택배물 배달까지 배송에서의 가능성과 함께 교내 손님 안내 등으로의 서비스까지 다양한 방면으로 생각할 수 있다.
 
 
 ## 🔶사용 시나리오

20*22년 5월 26일,*

<aside>
💡 청파제 프로그램 : 부족했던 감성을 채워줄 자율주행 자동차, 포피스(Poffice)🚗 가 온다.

</aside>

- waypoint로 생성된 경로를 따라 자율주행으로 축제 기간 동안 학교 캠퍼스를 도는 포피스를 통해 숙명인들에게서 손편지를 수집한다.
- 수집한 손편지들과 함께 포피스는 행사부스로 도착하고, 이후 사회자는 몇 개의 편지를 추첨해서 사연을 읽고 선물도 증정하는 방식으로 이벤트가 진행된다.
- 자율주행 포피스로 사람들의 관심을 끔과 동시에 아날로그 감성을 살리는 이벤트로 한다.
- 포피스 프로토타입 사진
    
    ![KakaoTalk_20211107_231816115](https://user-images.githubusercontent.com/69629703/140650125-222e13eb-ae3d-4bc6-9051-c91f744d95f2.jpg)

    ![KakaoTalk_20211107_231816115_01](https://user-images.githubusercontent.com/69629703/140650130-855d6b6e-98cc-45fb-be3f-c7bbc9f0b954.jpg)

    
