#include"passengerlist_class.h"

//create the linked list
void PassengerList::Create() {

	Passenger *current = NULL;
	Passenger *previous = head_;

	for (int i = 1; i < total_; ++i) {
		
		current = new Passenger(i);
		previous->next_ = current;
		previous = current;
	}
	current->next_ = head_;

	return;
}

//kill the unlucky guys
void PassengerList::Kill() {

	Passenger *start = head_->next_;
	Passenger *previous = head_;

	//find the start position
	for (int i = 1; i < startnum_; ++i) {

		start = start->next_;
		previous = previous->next_;
	}

	Passenger *current = start;

	//count the killed guys number
	for (int deathcount = 0; deathcount != total_ - residue_; ++deathcount) {

		//find the unlcky guys with the death number
		for (int i = 1; i != deathnum_; ++i) {

			previous = previous->next_;
			current = current->next_;
		}

		previous->next_ = current->next_;
		int num = current->num();

		//just for aligning
		if (deathcount < 10)
			cout << "��" << deathcount << "�����ߵ�λ���ǣ�      " << num << endl;
		else if (deathcount < 100)
			cout << "��" << deathcount << "�����ߵ�λ���ǣ�     " << num << endl;
		else if (deathcount < 1000)
			cout << "��" << deathcount << "�����ߵ�λ���ǣ�    " << num << endl;
		else
			cout << "��" << deathcount << "�����ߵ�λ���ǣ�   " << num << endl;
		
		//if about to delete the head, let the node before the old head be the new head
		if (current == head_)
			head_ = previous;
		 
		//kill the unlcky guys
		auto deletenode = current;
		current = current->next_;
		delete deletenode;
	}

	return;
}

//print the lucky guys
void PassengerList::SurvivalListOutput() {

	cout << endl << "���ʣ�£�     " << residue() << "��" << endl
		<< "ʣ������λ��Ϊ��         ";

	Passenger *current = head_->next_;

	while (current != head_) {

		int num = current->num();

		//just for aligning
		if (num < 10)
			cout << num << "       ";
		else if (num < 100)
			cout << num << "      ";
		else if (num < 1000)
			cout << num << "     ";
		else
			cout << num << "    ";

		current = current->next_;

	}

	int num = current->num();

	//just for aligning
	if (num < 10)
		cout << num << "       ";
	else if (num < 100)
		cout << num << "      ";
	else if (num < 1000)
		cout << num << "     ";
	else
		cout << num << "    ";
	cout << endl;

	return;
}