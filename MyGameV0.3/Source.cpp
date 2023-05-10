#include<iostream>
#include<string>
#include<ctime>
using namespace std;

class Equipment;


class Humanoid {
public:
	//Full parameter creation
	Humanoid(string classname,string name,int hp, int dmg, int str)
	{
		this->classname = classname;
		lvl = 1;
		this->name = name;
		this->hp = hp;
		this->dmg = dmg;
		this->str = str;
		this->id = count;

		count++;

		InventoryArray[str];
		FillWithNull();
	}	   

	//Name and class choice creation (FOR PLAYER ONLY)
	Humanoid(string name, int choice)
	{
		switch (choice)		//class choice
		{
		case 1:		//knight
			this->classname = "Knight";
			lvl = 1;
			this->name = name;
			this->hp = 40;
			this->dmg = 7;
			this->str = 8;
			this->id = count;

			count++;
			
			InventoryArray[str];
			FillWithNull();
			break;
		case 2:		//Mage
			this->classname = "Mage";
			lvl = 1;
			this->name = name;
			this->hp = 28;
			this->dmg = 13;
			this->str = 4;
			this->id = count;

			count++;
			
			InventoryArray[str];
			FillWithNull();
			break;
		case 3:		//
			this->classname = "Archer";
			lvl = 1;
			this->name = name;
			this->hp = 32;
			this->dmg = 10;
			this->str = 6;
			this->id = count;

			count++;
			
			InventoryArray[str];
			FillWithNull();
			break;
		}
	}		

	//Default, just creates knight
	Humanoid()
	{
		this->classname = "Knight";
		lvl = 1;
		this->name = name;
		this->hp = 40;
		this->dmg = 7;
		this->str = 8;
		this->id = count;

		

		count++;
		this->InventoryArray[str]; 
		for (int i = 0; i < str; i++)
		{
			 InventoryArray[i] = 0;
		}
		
	}

	//Getters
	string GetClassName(){
		return classname;
	}
	string GetName() {
		return name;
	}
	int GetLvl() {
		return lvl;
	}
	int GetHp() {
		return hp;
	}
	int GetDmg() {
		return dmg;
	}
	int GetStr() {
		return str;
	}
	int GetId() {
		return id;
	}

	static int GetCount(){
		return count;
	}


	//Setters
	void SetClassName(string classname){
		this->classname = classname;
	}
	void SetName(string name) {
		this->name = name;
	}
	void SetLvl(int lvl) {
		this->lvl = lvl;
	}
	void SetHp(int hp) {
		this->hp = hp;
	}
	void SetDmg(int dmg) {
		this->dmg = dmg;
	}
	void SetStr(int str) {
		this->str = str;
	}

	//Methods
		


	//Print humanoid info to console
	void PrintInfo()
	{
		cout << GetName() << " " << GetClassName() << " lvl: " << GetLvl()<<endl;
		cout << "Hp: " << GetHp() << endl;
		cout << "Dmg: " << GetDmg() << endl << endl;
		cout << "Inventory: " << invspace << " of " << GetStr() << endl;
	}
	
	//Leveling up, +HP, +DMG, +LVL, +STR
	void LevelUp(int value)
	{
		for (int i = 0; i < value; i++)
		{
			lvl++;
			hp += 8 + lvl;
			dmg += 3 + lvl;
			lvl % 2 ? str = str : str++;
		}
	}

	//Leveling up without value (annding more than one level)
	void LevelUp()
	{
		lvl++;
		hp += 8 + lvl;
		dmg += 3 + lvl;
		lvl % 2 ? str = str : str++;
		if (lvl % 2)
		{
			str = str;
		}
		else
		{
			str++;
			this->InventoryArray[str] = 0;
		}
	}

	//Print inventory cells
	void PrintInventoryArray()
	{
		for (int i = 0; i < str; i++)
		{
			cout << InventoryArray[i] << " ";
		}
	}

	//Deletes all the information from inventory array and recreates it
	void CreateNewArray()
	{
		int *InventoryArray = new int[this->GetStr()];

	}



	//Destructor
	~Humanoid()
	{
		delete[]InventoryArray;
	}

	
private:

	//Use ONLY to fill every Inventory cell with 0 (Clear inventory)
	void FillWithNull()
	{
		for (int i = 0; i < 100; i++)
		{
			InventoryArray[i] = 0;
		}
	}

	//Counting objects
	int static count;

	string classname = " ";	//classname
	string name = " ";		//name
	int lvl = 0;			//humanoid level
	int hp = 0;				//humanoid hp
	int dmg = 0;			//humanoid damage
	int str = 0;			//strength
	int invspace = 0;		//how much cells is filled

	//Use Print eqpitems as friend function
	friend void PrintEquippedItems(Humanoid& entity);

	//Use equipitem as friend function
	friend void EquipItem(Humanoid& entity, Equipment& object);

	//Unequip item friend function 
	friend void UnEquipItem(Humanoid& entity, Equipment& object);

	//Object id. Every object gets and id that==count of created objects
	int id = 0;	
	int* InventoryArray = new int[100];
};

int Humanoid::count = 0;

class Equipment
{
public:
	
	//Full parameter creation
	Equipment(string name, int Bhp, int Bdmg, int weight, int space)
	{
		count++;

		this->name = name;
		this->BonusHp = Bhp;
		this->BonusDmg = Bdmg;
		this->Weight = weight;
		this->Space = space;
		this->id = count;
		EqpStatus = false;
	}
	
	//Getters
	string GetName() {
		return name;
	}
	int GetBonusHp() {
		return BonusHp;
	}
	int GetBonusDmg() {
		return BonusDmg;
	}
	int GetWeight() {
		return Weight;
	}
	int GetSpace() {
		return Space;
	}
	int GetId() {
		return id;
	}
	bool GetEqpStatus()
	{ 
		return EqpStatus;
	}

	static int GetCount()
	{
		return count;
	}

	void PrintInfo()
	{
		cout << "Name: " << GetName() << endl;
		BonusHp != 0 ? cout << "Hp bonus: " << GetBonusHp() << endl : cout << "";
		BonusDmg != 0 ? cout << "Dmg bonus: " << GetBonusDmg() << endl : cout << "";
		cout << "Weight: " << GetWeight() << endl;
		cout << "Space capacity: " << GetSpace() << endl;
		if (EqpStatus)
		{
			cout << "Equipped"<<endl;
		}
		else
		{
			cout << "Unequipped" << endl;
		}
	}

	//Setters
	void SetName(string name) {
		this->name = name;
	}
	void SetBonusHp(int Bhp) {
		this->BonusHp = Bhp;
	}
	void SetBonusDmg(int Bdmg) {
		this->BonusDmg = Bdmg;
	}
	void SetWeight(int Weight) {
		this->Weight = Weight;
	}
	void SetSpace(int Space) {
		this->Space = Space;
	}
	void SetEqpStatus(bool some)
	{
		this->EqpStatus = some;
	}
	
private:
	string name = " ";	//Object name
	int BonusHp;		//Object bonus hp
	int BonusDmg;		//Object bonus dmg
	int Weight;			//Object weight
	int Space;			//Object space fill
	int id;				//Object id. Every object gets and id that==count of created objects
	bool EqpStatus;		//Object is equipped?

	//Counting objects
	static int count;

	//Use Print eqpitems as friend function
	friend void PrintEquippedItems(Humanoid& entity);

	//Use equipitem as friend function
	friend void EquipItem(Humanoid& entity, Equipment& object);
	
	
	//class Humanoid is friendly to Equipment, class Humanoid can freely use Equipment parameters
	friend Humanoid;
};

//create array of Pointers to objects of Equipment class
static Equipment* arragorn[20];

//Default initialization to Equipment::count = 0;
int Equipment::count = 0;

//Function to equip item to entity
void EquipItem(Humanoid& entity, Equipment& object)
{			//if weight of object less than entity strenght, or object space less than free inventory space, or object is equipped, than object cannot be equipped
	if ((object.Weight <= entity.str) && (object.Space <= (entity.str - entity.invspace))&&object.EqpStatus==false)
	{
			int checkSpace = 0;		//we create chackSpace to control filling of inventory cells
			for (int j = 0; j < entity.str+1; j++)
			{
				if(entity.InventoryArray[j]==0)		//check if cell is empty
				{
					entity.InventoryArray[j] = object.id;		//if cell is empty, than we initialize cell with object id
					checkSpace++;								//checkspace++ means that cell was initialized with object id and we can move forward
				}
				if (checkSpace == object.Space)					//when checkspace equals object.Space, we stop initializing inventory cells
				{
					break;
				}
			}
		object.EqpStatus = true;				//Object status changes to "Equipped"
		entity.invspace += object.Space;		//We andd object.space to entity.invspace to indicate that inventory is filled with this object
		
		entity.SetDmg(entity.GetDmg()+object.GetBonusDmg());		//Adding bonus dmg to entity dmg
		entity.SetHp(entity.GetHp() + object.GetBonusHp());			//Adding bonus hp to entity hp
		arragorn[object.GetId()] = &object;				//We add object to equipped objects array named arragorn by id
	}

	//If something went wrong: 
	else if (object.EqpStatus != false)
	{
		cout << endl << "Object cannot be equipped!" << endl << endl;
	}
	else if(object.Weight > entity.str)
	{
		cout << endl<<"Not enough strenght to equip!"<<endl<<endl;
	}
	else if (object.Space > (entity.str - entity.invspace))
	{
		cout << endl << "Not enough inventory space to equip!" << endl << endl;
	}
	
}

//Print all equipped objects
void PrintEquippedItems(Humanoid& entity)
{
	for (int i = 1; i <= Equipment::count; i++)
	{
		for (int j = 0; j < entity.str; j++)
		{
			if (entity.InventoryArray[j] == i)
			{
				arragorn[i]->PrintInfo();
				
				cout << endl;
				break;
			}
		}
	}
}

void UnEquipItem(Humanoid& entity, Equipment& object)
{
	if (object.GetEqpStatus() == 1)
	{
		for (int i = 0; i < entity.GetStr(); i++)
		{
			if (entity.InventoryArray[i] == object.GetId())
			{
				entity.InventoryArray[i] = 0;
			}
		}

		object.SetEqpStatus(false);

		entity.SetDmg(entity.GetDmg() - object.GetBonusDmg());
		entity.SetHp(entity.GetHp() - object.GetBonusHp());

		entity.invspace = (entity.invspace - object.GetSpace());

		arragorn[object.GetId()] = 0;
	}
	else
	{
		cout << "Object is already unequipped!" << endl;
	}
}

int main()
{
	Humanoid Eden("eden", 1);
	Equipment Axe("Battle axe", 0, 6, 5, 3);
	Equipment Shield("Shield", 8, 0, 4, 5);

	Eden.PrintInventoryArray();
	cout << endl;
	Eden.PrintInfo();

	EquipItem(Eden, Axe);
	
	cout << endl;

	Eden.PrintInventoryArray();
	cout << endl;
	Eden.PrintInfo();

	cout << endl;

	EquipItem(Eden, Shield);

	Eden.PrintInventoryArray();
	cout << endl;
	Eden.PrintInfo();
	
	UnEquipItem(Eden, Axe);
	cout << endl;

	Eden.PrintInventoryArray();
	cout << endl;
	Eden.PrintInfo();
	
	UnEquipItem(Eden, Shield);
	cout << endl;

	Eden.PrintInventoryArray();
	cout << endl;
	Eden.PrintInfo();

	
	return 0;
}
