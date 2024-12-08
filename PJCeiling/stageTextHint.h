#pragma once
char stageText[19][8][50] = {
	//튜토1
	{
		{"눈을 뜨니 낯선천장이 보인다."},
		{"일단 여기서 나가야할 것 같다."},
		{"'★'이 있는 곳까지 이동해보자."},
		{" "},
		{"길을 막는 블록을 밀거나"},
		{"건너뛰어서 지나가보자."}
	},
	//튜토 2
	{
		{"출구로 내려가니 새로운 공간이다."},
		{"폭탄이 있다. 이걸로 블록을 부숴볼까"},
		{"일단 계속 밑으로 내려가보자"},
		{ " " },
		{"구멍에 블록을 밀어보자"},
		{"질주를 사용하기 전에 길을 만들자"}
	},
	//튜토3
	{
		0,
	},
	//금고
	{
		{"한가운데 금고가 있다."},
		{"금고안에 뭐가 들어가 있을까.."},
		{"확인해보자"},
		{ " " },
		{"블록을 구멍에 밀어넣어보자."}
	},
	//부수고 당겨라
	{
		{"아래층으로 내려가야한다"},
		{"눈앞에 장애물들을 파괴해보자"},
		{ " " },
		{ " " },
		{"배터리 블록을 활성화시켜보자"},
	},
	//용광로
	{0,},
	//바람을 뚫어라
	{0,},
	//낯선 방탈출
	{0,},
	//맵연결
	{
		{"출구가 보이지 않는다."},
		{"우선 배터리로 콘센트를 켜보자"},
		{"콘센트를 키면 길이 열릴 것 같다."},
		{" "},
		{"직선 길을 만들어 질주를 사용하자"},
		{"밀기를 이용해 코스트를 아끼자."},
	},
	//가장 빠른 트랙
	{0,},
	//섬 탈출
	{0,},
	//강풍
	{
		{"어디선가 강한 바람이 불어온다"},
		{"바람을 막으며 앞으로 한칸씩"},
		{"전진해보자"},
		{" "},
		{"무거운 블록으로 선풍기를 막아서"},
		{"블록을 한칸씩 옮겨보자"}
	},
	//선풍기 개척
	{0,},
	//블록 생성기
	{
		{"사방이 이어져 있다."},
		{"안쪽까지 길을 이을 방법이"},
		{"뭐가 있을까…"},
		{" "},
		{"블록을 만들어 길을 이어보자."},
		{"그랩으로 전원을 끄고 켜보자."}
	},
	//징검다리
	{
		{"가운데 커다란 구멍이 있다."},
		{"중간중간 블록이 위태롭게 쌓여있다."},
		{"블록을 떨어뜨려 길을 만들어 보자"},
		{" "},
		{"블록을 떨어뜨리는 순서가 있다."},
		{"질주로 갈 수있는 순서를 찾아보자"}
	},
	// 일방통행
	{
		{"여기도 사방이 이어져 있다."},
		{"포탈을 블록이 막고 있어 한쪽방향"},
		{"으로만 갈수 있는 것 같다."},
		{" "},
		{"블록을 뛰거나 부숴 포탈을 이용하자"},
		{"열쇠를 다 먹을 필요는 없어보인다."}
	},
	//열쇠 콜렉터
	{
		{"거의 다 온것 같다."},
		{"근처에 자물쇠가 엄청 많다."},
		{"열쇠를 찾아 자물쇠를 열어보자"},
		{" "},
		{"출구 앞의 구멍블록 4개를 없애보자."},
		{"무거운 블록으로 선풍기 2개를 막자."}
	},
	//상승과 하강
	{
		{"전원을 키면 특정 구역이 상승한다."},
		{"배터리를 잘 활용 해보자"},
		{" "},
		{"구역의 전원을 끄면 블록은 길을"},
		{"만들어 준다."},
		{"이 길로 배터리를 옮겨보자"}
	},
	//엔딩
	{
		{"밖이 보이기 시작한다."},
		{"이 지긋지긋한 곳을 나가자."}
	}
};

char endingImage[27][100] = {
	{"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"},
	{"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"},
	{"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"},
	{"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"},
	{"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"},
	{"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"},
	{"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"},
	{"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"},
	{"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"},
	{"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"},
	{"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"},
	{"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"},
	{"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"},
	{"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"},
	{"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"},
	{"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"},
	{"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"},

};