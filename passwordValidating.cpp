#include "passwordValidating.h"

const char* symbols = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
const int symbols_len = 94;

void passwordValidate(System::String^ password, bool &check)
{
	for (int i = 0; i < password->Length; i++)
	{
		check = 0;
		for (int y = 0; y < symbols_len; y++)
		{
			if (password[i] == symbols[y])
			{
				check = 1;
				break;
			}
		}
	}
}

int passwordRating(System::String^ password)
{
	bool check = 0;
	if (password->Length > 7)
	{
		bool& linkcheck = check;
		passwordValidate(password, linkcheck);
	}

	if (check)
	{
		const char* specialSymbols = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
		const int spcialSymbols_len = 32;

		const char* alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
		const int alphaber_len = 52;

		const char* digits = "0123456789";
		const int digits_len = 10;

		int lengthPassword = password->Length;

		int specialSymbols_counter = 0;
		int digits_counter = 0;
		int alphabetUppercase_counter = 0;
		int alphabetLowercase_counter = 0;
		for (int i = 0; i < lengthPassword; i++)
		{
			for (int y = 0; y < spcialSymbols_len; y++)
			{
				if (password[i] == specialSymbols[y])
				{
					specialSymbols_counter++;
				}
			}

			for (int y = 0; y < digits_len; y++)
			{
				if (password[i] == digits[y])
				{
					digits_counter++;
				}
			}

			for (int y = 0; y < alphaber_len / 2; y++)
			{
				if (password[i] == alphabet[25 + y])
				{
					alphabetUppercase_counter++;
				}
			}

			alphabetLowercase_counter = lengthPassword - specialSymbols_counter - digits_counter - alphabetUppercase_counter;
		}

		if (lengthPassword < 11)
		{
			return 1;
		}
		else
		{
			if (specialSymbols_counter > 2 && alphabetUppercase_counter > 2 && digits_counter > 2)
			{
				if (specialSymbols_counter > 5 && alphabetUppercase_counter > 3 && digits_counter > 3 && alphabetLowercase_counter > 3)
				{
					if (lengthPassword < 18)
					{
						return 2;
					}
					return 3;
				}
				return 2;
			}
			return 1;
		}
	}
}
