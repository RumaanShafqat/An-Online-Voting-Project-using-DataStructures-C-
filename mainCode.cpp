#include<iostream>
using namespace std;
class node {
	public:
		string data;
		node*next;
		int count;
		node() {
			cin>>data;
			next=NULL;
			count=0;
		};


};
class members {

	public:

		int arr[5];
		node*head;
		node*current;
		members() {
			head=NULL;
			current=NULL;
		};





		void insert() {
			cout<<"ENTER NAMES OF CANDIDATES"<<endl;
			node*newnode=new node();
			if(head==NULL) {
				head=newnode;
			} else {
				current=head;
				while(current->next!=NULL) {
					current=current->next;
				}
				current->next=newnode;

			}
		};

		void punjab() {
			for(int i=1; i<=5; i++) {
				insert();
			};
		};
		void display1() {
			current=head;
			while(current!=NULL) {
				cout<<current->data;
				cout<<",";
				current=current->next;
			}

		};
		// calcilate vote
		void VOTE(string membername) {
			current=head;
			while(current!=NULL) {
				if(current->data==membername) {
					cout<<"YOU HAVE VOTED:"<<membername;
					cout<<endl;
					current->count++;


					return ;
				}

				current=current->next;
			}
			cout<<"not fund";


		};
		void converter(node*head,string arr_one[]) {
			node*current=head;
			int temp=0;
			while(current!=NULL&&temp<5) {
				arr_one[temp++]=current->data;
				current=current->next;
			}
		};
		void calculatevote() {
			cout<<"TOTAL NUMBER OF VOTES #  "<<endl;
			cout<<endl;
			current = head;
			while (current != NULL) {
				cout << current->data << " HAVE TOTAL Votes: " << current->count << endl;
				current = current->next;
			};
		};

		void votetotal() {

			cout<<endl;
			string arr_one[5];
			cout<<"I STORE MY LINKLIST IN ARRAY"<<endl;
			converter(head,arr_one);

			for(int i=0; i<5; i++) {

				cout<<arr_one[i]<<" ";
			}
			cout<<"                       ENTER YOUR VOTE FOR JUST ONE CANDIDATE"<<endl;
			cout<<endl;
			string name;
			cin>>name;
			cout<<endl;
			VOTE(name);
			cout<<"                if i want votes from some more users"<<endl;

			//result and entries from user
			string vote;
			cout<<"LETS HAVE MORE VOTES"<<endl;
			while(true) {

				cin>>vote;
				if(vote=="done") {
					break;
				}
				VOTE(vote);
			}

			calculatevote();

		};

		void function() {
			votetotal();
		};
};
class sindh:public members {

	public:
		void getcan() {
			for(int i=0; i<5; i++) {
				insert();
			};
		};
		void display2() {
			cout<<"THESE ARE THE CANDIDATES OF SINDH"<<endl;
			current=head;
			while(current!=NULL) {
				cout<<current->data;
				cout<<",";
				current=current->next;
			}

		}

		void function() {
			votetotal();
		}




};
class balochistan:public members {

	public:
		void getcan() {
			for(int i=0; i<5; i++) {
				insert();
			};
		};
		void display3() {
			cout<<"THESE ARE THE CANDIDATES OF BALOCHISTAN"<<endl;
			current=head;
			while(current!=NULL) {
				cout<<current->data<<endl;
				cout<<",";
				current=current->next;
			}


		}

		void function() {
			votetotal();
		}
};
void getdigit() {
	int count =0;
	long long int  n;
	cout<<"ENTER  your CNIC :"<<endl;
	cin>>n;

	while(n!=0) {


		n/=10;
		++count;
	};
	cout<< count;

	if(count==13) {

		cout<<"                     VALID  CNIC "<<endl;
		cout<<"                     !!!! WELCOME TO ONLINE VOTING BY ELECTION COMMISION OF PAKISTAN!!!!!"<<endl;

	} else {
		cout<<"                        INVALID  CNIC  "<<endl;
		cout<<"                        ...try again..."<<endl;
		cout<< "                       PLEASE ENTER AGAIN    "<<endl;
		getdigit();
	}
};

int main() {
//                                         candidates ko linklist mein store krwanay k lie
//                                         consider we have 5 ,5 candidates in every province
	cout <<"           ENTER CANDIDATES              "<<endl;

	members m1;
	cout<<"                                            enter 5 candidates of punjab "<<endl;
	cout<<endl;
	m1.punjab();
	m1.display1();

	sindh s1;
	cout<<"                                            enter 5 candidates for sindh "<<endl;
	cout<<endl;
	s1.getcan();
	s1.display2();
	cout<<"                                           enter 5 candidates for balochistan "<<endl;
	cout<<endl;

	balochistan b1;
	b1.getcan();
	b1.display3();
	//                                we have store candidates in our linklist now it's time to be user now
	cout<<                          "                   LOG-IN PAGE	"<<endl;
	long long int n;
	cout<<"                                           WELCOME TO CAST YOUR VOTE  "<<endl;



	getdigit();


	string area;
	string punj="PUNJAB";
	string sindh="SINDH";
	string kkpk="KPK";
	string balochistan="BALOCHISTAN";
	cout<<endl;
	cout<<          "           ENTER YOUR AREA "<<endl;
	cin>>area;
	if(area==punj) {
		m1.display1();
		m1.function();

	}

	else if(area==sindh) {
		s1.display2();
		s1.function();


	}

	else if(area==balochistan) {
		b1.display3();
		//uper walay function ko call kia hai jo balochistan main rakha tha jis mein totalvote wala func tha
		b1.function();

	}


	else {
		cout<<"        OH SORRY !!YOU ARE ENTERING WRONG AREA"<<endl;
		cout<<"        please enter right area"<<endl;


	};

	return 0;
};

