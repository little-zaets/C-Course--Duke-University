#include <stdio.h>
#include <stdlib.h>

struct _retire_info
{
  int months; /* applicable months */
  double contribution; /* how many dollars contributed or spent(if retired) */
  double rate_of_return; /* interest rate */
};
typedef struct _retire_info retire_info;

void printBalance(double balance, int age)
{
  int year = age/12;
  int months = age%12;
  printf("Age %3d month %2d you have $%.2f\n", year, months, balance);
}

double monthlyBalance(retire_info balance, double current_balance)
{
  double interest_earned;
  balance.rate_of_return /= 12;
  interest_earned =  balance.rate_of_return * current_balance;
  current_balance = (current_balance + interest_earned) + balance.contribution;
  return current_balance;
}


    
void retirement(int startAge, double initial, retire_info working, retire_info retired)
{
  double current_balance = initial;
  int current_age = startAge;
  int total_age = startAge + working.months + retired.months;
  working.months += startAge;

  while (current_age < total_age)
    {
      printBalance(current_balance, current_age);
      if ( current_age < working.months )
	{
	  current_balance = monthlyBalance(working, current_balance);
	}
      else
	{
	  current_balance = monthlyBalance(retired, current_balance);
	}
      ++current_age;
    }
}

int main (void)
{
  retire_info working;
  retire_info retired;
  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = 0.045;
  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = 0.01;

  retirement(327, 21345, working, retired);

  return 0;
}
