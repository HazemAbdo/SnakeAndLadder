#include "Player.h"

#include "GameObject.h"

Player::Player(Cell* pCell, int playerNum) : stepCount(0), wallet(100), playerNum(playerNum)
{
	freeze = false; // so the player can move  
	//============ the player is not affected yet ===================
	Fire_affected = 0;

	Poison_affected = 0;

	Lightning = false;

	for (int i = 0;i < 4;i++)
	{
		UsedAttacks[i] = false; // the player didn't use any attack yet
	}
	UsedAttacksNumber = 0;

	this->pCell = pCell;
	this->turnCount = 0;

}

// ====== Setters and Getters ======

void Player::SetCell(Cell* cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

void Player::SetWallet(int wallet)
{
	this->wallet = wallet;
}

int Player::GetWallet() const
{
	return wallet;
}

int Player::GetTurnCount() const
{
	return turnCount;
}
int Player::GetJustRolledDiceNum()
{
	return justRolledDiceNum;
}
// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];


	///TODO: use the appropriate output function to draw the player with "playerColor"
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, playerColor);
}

void Player::ClearDrawing(Output* pOut) const
{
	color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard;


	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, cellColor);
}

// ====== Game Functions ======

void Player::Move(Grid* pGrid, int diceNumber)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==


	// 1- Increment the turnCount because calling Move() means that the player has rolled the dice once
	// 2- Check the turnCount to know if the wallet recharge turn comes (recharge wallet instead of move)

	//    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	if (Fire_affected > 0)// if the player is attacked with fire
	{
		pGrid->PrintErrorMessage(" You are attacked with Fire so wallet will decrease by 20  ");
		wallet -= 20;
		Fire_affected--;

	}

	if (Poison_affected > 0)// if the player is attacked with poison
	{
		diceNumber--;
		Poison_affected--;
		pGrid->PrintErrorMessage(" You are attacked with poison so Roll Dice : " + to_string(diceNumber));
	}

	if (Lightning)// if the player is attacked with Lightning
	{
		pGrid->PrintErrorMessage(" You are attacked with Lightning so wallet will decrease by 20  ");
		wallet -= 20;
		Lightning = false;
	}

	if (freeze)
	{
		pGrid->PrintErrorMessage(" you are denied from playing this turn. Click to continue  ");
		freeze = false;
		return;
	}

	if (++turnCount == 3)
	{
		turnCount = 0; //reset the counter
		string in_string = "";

		if (UsedAttacksNumber == 2) // so that the player can't use more than two special attacks
			in_string = "n";

		while (in_string != "y" && in_string != "Y" && in_string != "n" && in_string != "N") {
			pOut->PrintMessage("Do you want to launch a special attack instead of recharging ? y/n ");
			in_string = pIn->GetSrting(pOut); //Gets the user choise
		}

		int  SpecialAttack = -1; // to store the special attack choise

		if (in_string == "n" || in_string == "N") {
			wallet += 10 * diceNumber;
			pGrid->PrintErrorMessage("Your Wallet increased by " + to_string(10 * diceNumber) + ", Click to continue");
			return;

		}
		else if (in_string == "y" || in_string == "Y")
		{
			while (!(SpecialAttack >= 1 && SpecialAttack <= 4))// the input is invalid
			{

				pOut->PrintMessage(" 1-Ice   2-Fire  3-Poison  4-Lightning ");
				SpecialAttack = pIn->GetInteger(pOut);

				if (UsedAttacks[SpecialAttack - 1]) {
					pGrid->PrintErrorMessage(" You Used This Attack before ,Click to continue ");
					SpecialAttack = -1; // invalid so it continue asking for input
				}
			}

			UsedAttacks[SpecialAttack - 1] = true; // so the player can't use this attack again
			UsedAttacksNumber++;
			int playerNumber = -1; // invalid so it continue asking for input

			switch (SpecialAttack) {

			case 1: // ice

				while (playerNumber < 0 || playerNumber>3)
				{

					pOut->PrintMessage("Use the attack on player number :");
					playerNumber = pIn->GetInteger(pOut);

					if (playerNumber == playerNum) { // if the user attack himself
						pGrid->PrintErrorMessage("Can't attack yourself ,Click to Continue ");
						playerNumber = -1; // invalid so continue getting input
					}
				}

				pGrid->Ice(playerNumber);
				break;

			case 2: //Fire
				while (playerNumber < 0 || playerNumber>3)
				{

					pOut->PrintMessage("Use the attack on player number :");
					playerNumber = pIn->GetInteger(pOut);

					if (playerNumber == playerNum) { // if the user attack himself
						pGrid->PrintErrorMessage("Can't attack yourself ,Click to Continue ");
						playerNumber = -1; // invalid so continue getting input
					}
				}
				pGrid->Fire(playerNumber);
				break;

			case 3: //Poison

				while (playerNumber < 0 || playerNumber>3)
				{

					pOut->PrintMessage("Use the attack on player number :");
					playerNumber = pIn->GetInteger(pOut);

					if (playerNumber == playerNum) { // if the user attack himself
						pGrid->PrintErrorMessage("Can't attack yourself ,Click to Continue ");
						playerNumber = -1; // invalid so continue getting input
					}
				}
				pGrid->Poison(playerNumber);
				break;

			case 4: //Lightning
				pGrid->Lightning(playerNum);
				break;

			}
			pGrid->PrintErrorMessage("Special attack is used ,click to continue");
			return;
		}

	}
	// 3- Set the justRolledDiceNum with the passed diceNumber
	justRolledDiceNum = diceNumber;

	// 4- Get the player current cell position, say "pos", and add to it the diceNumber (update the position)
	if (wallet > 0)
	{
		CellPosition pos = pCell->GetCellPosition();
		//    Using the appropriate function of CellPosition class to update "pos"

		if (diceNumber + pos.GetCellNumFromPosition(pos) >= 99) {//if the player won the game
			diceNumber = 99 - pos.GetCellNumFromPosition(pos); //so the player moves only to the last cell  
		}

		pos = pos.GetCellPositionFromNum(diceNumber + pos.GetCellNumFromPosition(pos));//it changes the position to the current position + the dice number

		// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
		pGrid->UpdatePlayerCell(this, pos);
		//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position

		// 6- Apply() the game object of the reached cell (if any)
		pCell->ApplyAction(pGrid, this);
		// 7- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)
		pos = pCell->GetCellPosition();

		pGrid->SetEndGame(pos.GetCellNumFromPosition(pos) == NumHorizontalCells * NumVerticalCells);
	}
	else
	{
		pOut->PrintMessage("You have to Wait Until Recharge your wallet");
	}

}



void  Player::MoveInSameTurn(Grid* pGrid, int num)
{
	CellPosition pos = pCell->GetCellPosition();

	if (num + pos.GetCellNumFromPosition(pos) >= 99) {//if the player won the game
		num = 99 - pos.GetCellNumFromPosition(pos); //so the player moves only to the last cell  
	}

	// 4- Get the player current cell position, say "pos", and add to it the diceNumber (update the position)

	//    Using the appropriate function of CellPosition class to update "pos"
	pos = pos.GetCellPositionFromNum(num + pos.GetCellNumFromPosition(pos));//it changes the position to the current position + the passed number

	// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
	pGrid->UpdatePlayerCell(this, pos);
	//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position

	// 6- Apply() the game object of the reached cell (if any)
	pCell->ApplyAction(pGrid, this);
	// 7- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)
	pos = pCell->GetCellPosition();
	pGrid->SetEndGame(pos.GetCellNumFromPosition(pos) == NumHorizontalCells * NumVerticalCells);
}


void Player::AppendPlayerInfo(string& playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(";
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}


void Player::SetFreeze(bool fre)
{
	freeze = fre;
}

void Player::AttackFire()
{
	Fire_affected = 3; // will be affected for 3 turns
}
void Player::AttackPoison()
{
	Poison_affected = 5; // will be affected for 5turns
}
void Player::AttackLightning()
{
	Lightning = true;
}

void Player::ResetUsedActions()
{
	freeze = false; // so the player can move  
	//============ the player is not affected yet ===================
	Fire_affected = 0;

	Poison_affected = 0;

	Lightning = false;

	for (int i = 0;i < 4;i++)
	{
		UsedAttacks[i] = false; // the player didn't use any attack yet
	}
	UsedAttacksNumber = 0;
	turnCount = 0;
}

