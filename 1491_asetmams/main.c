
#define average average_salary

double average_salary(int *salary, int salary_size)
{
	int min = salary[0], max = salary[0];
	double total_salary = 0.0;

	for (int i = 0;i < salary_size;++i)
	{
		min = (min > salary[i]) ? salary[i] : min;
		max = (max < salary[i]) ? salary[i] : max;
		total_salary += salary[i];
	}
	return (total_salary - min - max) / (salary_size - 2);
}
