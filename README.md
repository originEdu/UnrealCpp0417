# 향상된 Input 복습 프로젝트
- 향상된 Input 블루프린트로 구현 후 세팅
- Base가 되는 Gamemode와 PlayerController, P38은 C++로 구현
- 이를 상속받은 BP_Gamemode와 BP_PlayerController와 BP_P38 블루프린트 생성
- C++만든 P38은 컴포넌트 구조 및 프로퍼티, 전방이동 구현되어 있다
- 이를 상속받은 BP_P38에 스테틱매쉬, Input Action 세팅
- C++ 만든 PlayerController은 InputMapping 프로퍼티 구현
- 이를 상속받은 BP_PlayerController에 Input Mapping Contextr 세팅
