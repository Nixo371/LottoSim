#include "lotto.h"
#include "get_next_line/get_next_line.h"

int	num_of_tickets = 1000000; 	//How many tickets you're playing each run
int	cost_of_ticket = 5;			//How much each ticket costs
int	num_of_prizes = 11;			//How many prizes there are
int	num_of_runs = 100;			//How many runs to do to find the average

int	check_ticket(int	(*prizes)[4])
{
	int	i;

	i = 0;
	while (i < num_of_prizes)
	{
		if(rand() % prizes[i][1] == 0)
			return (prizes[i][0]);
		i++;
	}
	return (0);
}

void	set_prizes(int	(*prizes)[4], int   n)
{
	int		i;
	int     fd;
	char	*reads;
	char	**temp;

	i = 0;
	fd = open("prizes.txt", O_RDONLY);
	if (!fd)
		return ;
	reads = malloc(200 * sizeof(char) + 1);
	if (!reads)
		return ;
	while(n > 0)
	{
		reads = get_next_line(fd);
		temp = ft_split(reads, '\t');
		prizes[i][0] = atoi(temp[0]);
		prizes[i][1] = atoi(temp[1]);
		prizes[i][2] = atoi(temp[2]);
		prizes[i][3] = atoi(temp[3]);
		i++;
		n--;
	}
	return ;
}

int main()
{
	int	i;
	int	j;
	int	bal;
	int	av_bal;

	i = 0;
	j = 1;
	bal = 0;
	av_bal = 0;
	t_prize lotto;
	set_prizes(lotto.prizes, num_of_prizes);
	srand (time(NULL));
	while (i < num_of_runs)
	{
		while (j <= num_of_tickets)
		{
			bal += check_ticket(lotto.prizes);
			j++;
		}
		bal -= num_of_tickets * cost_of_ticket;
		av_bal += bal / num_of_runs;
		bal = 0;
		j = 1;
		i++;
		printf("Run %d of %d completed...\n", i, num_of_runs);
	}
	printf("Number of tickets: %d\n", num_of_tickets);
	printf("Number of runs: %d\n", num_of_runs);
	printf("Total cost: $%d\n", num_of_tickets * cost_of_ticket);
	if (av_bal < 0)
		printf("Average loss of $%d...\n", -av_bal);
	else if (av_bal > 0)
		printf("Average winnings of $%d\n", av_bal);
	else
		printf("You broke even on average\n");
}