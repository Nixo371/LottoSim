# LottoSim
Customizable lottery simulator

git clone --recurse-submodules -j8 https://github.com/Nixo371/LottoSim

Edit the global variables in main.c to your liking

prizes.txt works this way:

PRIZE OUTCOME		1 in x odds			total prizes available			total prizes remaining

Ex:

100						20						100								80

$100 prize ocurring 1 in every 20 rolls/tickets. There are a total of 100 prizes, of which 80 remain.

The total prizes available/remaining is not factored in, but you are welcome to submit a pull request to add it in!

I've dabbled with the idea of making a more manual version, where you hit a key (probably enter/return) to "draw" the next ticket. However I feel this is a tool more than it is a game.

NOTE: rand() function returns a number from 1 to 2,147,483,647 on LINUX. On Windows it will return a number from 1 to 32,768. This will make any probabilities 1 in x where x is greater than 32,768 impossible. So keep that in mind.