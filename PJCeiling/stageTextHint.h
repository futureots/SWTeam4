﻿#pragma once
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
		{"슬라임이다."},
		{"모든 블록을 다 녹이고 있다."},
		{"용광로도 보인다. 조심히 가보자."},
		{" "},
		{"용광로는 단단한 블록을 생성한다."},
		{"슬라임 블록에 닿아보자."},
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
	{
		{"정신이 없다. 몸도 뜨겁다"},
		{"용광로 때문이었다."},
		{"다행이 몸은 멀쩡하다."},
		{ " " },
		{"단단한 블록을 끝까지 옮겨보자."},
		{"코너에 박힌 블록은 그랩을 사용하자."}
	},
	//바람을 뚫어라
	{
		{"바람이 분다."},
		{"뜨거웠던 몸이 식어간다."},
		{"선풍기들을 뚫고 가야 할 거 같다."},
		{ " " },
		{ "건너가서 단단한 블록을 가져오자." },
		{ "슬라임 블록을 조심하자." }
	},
	//낯선 방탈출
	{
		{ "조용하다." },
		{ "매우 낯선 방이다." },
		{ "앞에 배터리를 작동해 봐야겠다." },
		{ " " },
		{"질주를 적극적으로 사용하자."},
		{"최대한 짧은 길을 생각하자." }
	},
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
	{
		{"속이 울렁거린다."},
		{"달리기 트랙이 보인다."},
		{"장애물들이 피해 가야 할 거 같다."},
		{" "},
		{"중간에 트랙을 바꾸며 이동하자."},
		{"가장 빠른 경로를 찾아야 한다."},
	},
	//섬 탈출
	{
		{"다리가 아프다. 비린내가 난다."},
		{"바다 냄새인지, 내 땀 냄새인지."},
		{"주변에 섬들이 보인다."},
		{" "},
		{"섬마다 할 수 있는 일들이 있다."},
		{"마지막 섬으로 가는 길을 열어보자."}
	},
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
	{
		{"또 지긋지긋한 바람이 분다."},
		{"선풍기 센서를 작동해야할 거 같다."},
		{"일단 배터리 블록을 움직여 보자."},
		{" "},
		{"블록을 움직여서 선풍기를 작동하자"},
		{"때로는 직접 길을 만들어 보자."},
	},
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