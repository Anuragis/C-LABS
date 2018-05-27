#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

/*** Complete this program. ***/

int main()
{
	const int UNITS_PER_CAN = 3;
	const string INPUT_FILE_NAME = "counts.txt";

	ifstream input;
	input.open(INPUT_FILE_NAME);
	if (input.fail())
	{
	cout << "Failed to open " << INPUT_FILE_NAME << endl;
	return -1;
	}

	int plant_count(0);
	// Loop once for each number of plants read from the input file.
	// Stop when the number of plants is 0 or less.
	// During each loop, simulate Plan Near and Plan Far.


	do
	{
	input >> plant_count;
	if(plant_count>0){

	// Plan Near
	cout << endl;
	cout << "==========================" << endl;
	cout << " Plan Near with " << plant_count << " plants" << endl;
	cout << "==========================" << endl;
	cout << endl;
	cout << "Where      Cum. steps  Water amt.  Cum. step-units" << endl;
	cout << "---------  ----------  ----------  ---------------" << endl;

	int cum_steps = 0;
	int water_amt = UNITS_PER_CAN;
	int near_cum_step_units = 0;
	int temp_plant_count = plant_count;
	int plants_no = 0;
	int steps_taken = 0;

	while (temp_plant_count >= 0) {

		if (water_amt > 0 && temp_plant_count>0) {

			steps_taken++;
			plants_no++;
			temp_plant_count--;

			cum_steps += 1;
			near_cum_step_units = near_cum_step_units + steps_taken*water_amt;

			cout << "Plant " << setw(2) << plants_no << setw(5) << cum_steps << setw(15) << water_amt << setw(15) << near_cum_step_units << endl;
		
			water_amt--;
			steps_taken = 0;
		}
		else {
			
			cum_steps = cum_steps + plants_no;
			
			cout << "FAUCET" << setw(7) << cum_steps << setw(15) << water_amt << setw(15) << near_cum_step_units << endl;
			
			cum_steps = cum_steps + plants_no;
			water_amt = 3;
			steps_taken = plants_no;
		}

		if (temp_plant_count == 0) {
			
			cum_steps = cum_steps + plants_no;
			steps_taken = plants_no;
			near_cum_step_units = near_cum_step_units + steps_taken*water_amt;
			
			cout << "FAUCET" << setw(7) << cum_steps << setw(15) << water_amt << setw(15) << near_cum_step_units << endl;
			break;
		}
		
	}
	cout << endl;
	cout << "Plan Near: " << "Total steps = " << cum_steps << ", total step-units = " << near_cum_step_units << endl;

	/*** Complete the code for Plan Near. ***/

	// Plan Far
	cout << endl;
	cout << "=========================" << endl;
	cout << " Plan Far with " << plant_count << " plants" << endl;
	cout << "=========================" << endl;
	cout << endl;
	cout << "Where      Cum. steps  Water amt.  Cum. step-units" << endl;
	cout << "---------  ----------  ----------  ---------------" << endl;

	cum_steps = plant_count;
	water_amt = UNITS_PER_CAN;
	int far_cum_step_units = 0;
	temp_plant_count = plant_count;
	plants_no = plant_count;
	steps_taken = plant_count;

	while (temp_plant_count >= 0)
	{
		if (water_amt > 0 && temp_plant_count>0) {
			
			far_cum_step_units = far_cum_step_units + steps_taken*water_amt;
			steps_taken=0;

			cout << "Plant " << setw(2) << plants_no << setw(5) << cum_steps << setw(15) << water_amt << setw(15) << far_cum_step_units << endl;

			plants_no--;
			temp_plant_count--;
			cum_steps += 1;
			water_amt--;
			steps_taken += 1;
		}
		else {
			cum_steps = cum_steps + plants_no;

			cout << "FAUCET" << setw(7) << cum_steps << setw(15) << water_amt << setw(15) << far_cum_step_units << endl;

			cum_steps = cum_steps + plants_no;
			water_amt = 3;
			steps_taken = plants_no;
		}
		if (temp_plant_count == 0) {
			steps_taken = 1;
			far_cum_step_units = far_cum_step_units + steps_taken*water_amt;
			
			cout << "FAUCET" << setw(7) << cum_steps << setw(15) << water_amt << setw(15) << far_cum_step_units << endl;
			break;
		}
		

	}
	cout << endl;
	cout << "Plan Far: " << "Total steps = " << cum_steps << ", total step-units = " << far_cum_step_units << endl;

	/*** Complete the code for Plan Far. ***/
	

	// Which plan is better? Better means fewer step-units.
	cout << endl;
	cout << "*** With " << plant_count << " plants, ";

	if (near_cum_step_units <= far_cum_step_units) {
		cout << "Plan Near is better with " << far_cum_step_units - near_cum_step_units << " fewer step-units." << endl;
	}
	else {
		cout << "Plan Far is better with " << near_cum_step_units-far_cum_step_units << " fewer step-units." << endl;
	}
	/*** Complete the code to determine the better plan. ***/
		}
	} while (plant_count > 0);

	return 0;
}