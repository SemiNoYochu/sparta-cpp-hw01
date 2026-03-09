#include <iostream>

void setPotion(int count, int* p_HPPotion, int* p_MPPotion);

int status[4] = { 0, };

int main()
{
	std::cout << "50 초과의 HP/MP를 입력해주세요." << std::endl;
	std::cin >> status[0] >> status[1];

	bool bInput = true;

	while (bInput)
	{
		if (50 >= status[0] || 50 >= status[1])
		{
			std::cout << "50 초과의 HP/MP를 입력해주세요." << std::endl;

			std::cin >> status[0] >> status[1];
		}
		else
		{
			bInput = false;
			break;
		}
	}

	bInput = true;

	std::cout << "0 초과의 ATK/DEF를 입력해주세요." << std::endl;
	std::cin >> status[2] >> status[3];

	while (bInput)
	{
		if (0 >= status[2] || 0 >= status[3])
		{
			std::cout << "0 초과의 ATK/DEF를 입력해주세요." << std::endl;

			std::cin >> status[2] >> status[3];
		}
		else
		{
			bInput = false;
			break;
		}
	}

	int menuNum = 7;

	int hpPotion = 5;
	int mpPotion = 5;

	while (menuNum)
	{
		std::cout << "1.HP UP / 2.MP UP / 3.공격력 UP / 4.방어력 UP / 5.현재 능력치 / 6.Level Up / 0.나가기" << std::endl;
		std::cin >> menuNum;

		setPotion(menuNum, &hpPotion, &mpPotion);
	}

	return 0;
}

void setPotion(int count, int* p_HPPotion, int* p_MPPotion)
{
	switch (count)
	{
	case 1:
		if (0 < *(p_MPPotion))
		{
			*(p_MPPotion) -= 1;
			status[1] += 20;
		}
		else
		{
			std::cout << "MP 포션이 부족합니다." << std::endl;
		}
		break;
	case 2:
		if (0 < *(p_HPPotion))
		{
			*(p_HPPotion) -= 1;
			status[0] += 20;
		}
		else
		{
			std::cout << "MP 포션이 부족합니다." << std::endl;
		}
		break;
	case 3:
		status[2] *= 2;
		break;
	case 4:
		status[3] += status[3];
		break;
	case 5:
		std::cout << "HP:" << status[0] << std::endl;
		std::cout << "MP:" << status[1] << std::endl;
		std::cout << "ATK:" << status[2] << std::endl;
		std::cout << "DEF:" << status[3] << std::endl;
		break;
	case 6:
		std::cout << "Level Up!" << std::endl;
		p_HPPotion += 1;
		p_MPPotion += 1;
		break;
	default:
		break;
	}
}