#pragma once

class Pet
{
private:
	const int MIN_STATE = 0;
	const int MAX_STATE = 100;

public:
	Pet();
	~Pet();

	void Eat();
	void Play();
	void Shower();
	void Sleep();

	void ShowInfo();
	bool IsDead();

private:
	void CreateName();
	int Clamp(int value, const int& min, const int& max); // 고정하다. 특정 MIN/MAX 수치에 수렴시키는 것
	int RandomInRange(const int& min, const int& max);
	void CalcState(int& value, const int& min, const int& max);
	void IncreaseExp(const uint& exp);

private:
	string name = "NoName";
	uint age = 0;
	uint exp = 0;
	int hp = MAX_STATE;
	int hunger = (MIN_STATE + MAX_STATE) / 2;
	int clean = MAX_STATE;
};