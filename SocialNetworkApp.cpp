

#include<iostream>
#include<fstream>

using namespace std;

class Helper
{
public:
	static int StringLength(const char* str)
	{
		int len = 0;
		for (int i = 0; str[i] != '\0'; i++)
		{
			len++;
		}

		return len;
	}

	static char* GetStringFromBuffer(const char* buffer)
	{

		int len = StringLength(buffer);
		char* str1 = new char[len + 1];

		for (int i = 0; i < len; i++)

		{
			str1[i] = buffer[i];
		}
		str1[len] = '\0';
		return str1;
	}

	static int Compare(const char* str1, const char* str2)
	{
		int len1 = StringLength(str1);
		int len2 = StringLength(str2);
		if (len1 != len2)
		{
			return 0;
		}
		for (int i = 0; i < len1; i++)
		{
			if (str1[i] != str2[i])
			{
				return 0;
			}
		}

		return 1;
	}

	static char* Concatenate(const char*& str1, const char* str2) // for concatenating str2 onto str1
	{
		int len1 = StringLength(str1);
		int len2 = StringLength(str2);
		int size = len1 + len2; // Total size of concatenated string

		char* temp = new char[size + 1];
		char* temp1 = temp;
		int counter = 0;

		for (int i = 0; i < len1; i++)
		{
			temp[counter++] = str1[i]; // traversing
		}

		for (int i = 0; i < len2; i++)
		{
			temp[counter++] = str2[i]; // traversing
		}

		temp[counter] = '\0'; // Ending string with a null

		return temp1;
	}

	static int CountDigits(int num) // to Count number of Digits 
	{
		int count = 0;
		while (num != 0)
		{
			num /= 10;
			count++;
		}
		return count;
	}

	static void ConvertToChar(char* arr, int num)
	{
		int NoOfDigits = CountDigits(num);
		int index = NoOfDigits - 1;
		while (num != 0)
		{
			arr[index--] = (num % 10) + '0';
			num /= 10;
			index--;
		}
		arr[NoOfDigits] = '\0';
	}

	static char* CreationOfPostID(const char* txt, int num)
	{
		int NoOfDigits = CountDigits(num);
		char* arr = new char[NoOfDigits - 1];
		ConvertToChar(arr, num);
		arr = Concatenate(txt, arr);
		return arr;

	}




};

class Date
{
	int day;
	int month;
	int year;
public:
	static Date PresentDate;

	Date()
	{
		day = 0;
		month = 0;
		year = 0;
	}

	void ReadDataFromFile(ifstream& fin)
	{
		fin >> day;
		fin >> month;
		fin >> year;
	}

	static	void SetPresentDate(int d, int m, int y)
	{
		PresentDate.day = d;
		PresentDate.month = m;
		PresentDate.year = y;

	}

	bool CompareDate()
	{
		if (year == PresentDate.year && month == PresentDate.month && PresentDate.day - day <= 2)
		{
			return 1;
		}

		return 0;

	}

	int CalculateYear()
	{
		return PresentDate.year - year;
	}

	int CheckDate()
	{
		if (year != PresentDate.year) return 0;
		if (month != PresentDate.month) return 0;
		if (PresentDate.day - day == 2) return 2;
		if (PresentDate.day - day == 1) return 1;
		if (day != PresentDate.day)  return 0;

		return -1;  // only if both dates are equal 

	}

	void SetValues(int d = 0, int m = 0, int y = 0)
	{
		day = d;
		month = m;
		year = y;
	}

	void DisplayDate()
	{
		cout << day << "/" << month << "/" << year;
	}
};

Date Date::PresentDate;


class Comments;
class Object;
class Post;
class Users;
class Pages;
class Controller;

class Object
{
	char* ID;
	int NoOfPosts;
	int NoOfTimelinePosts;

	Post** Timeline;   // collection of posts for each user/page 
public:
	void ViewTimeline();
	void ViewCustomTimeline();


	Object()
	{
		ID = 0;
		Timeline = 0;
		NoOfPosts = 0;
		NoOfTimelinePosts = 0;
	}
	virtual ~Object();

	void SetID(char* buffer)
	{
		ID = new char[Helper::StringLength(buffer) + 1];
		ID = Helper::GetStringFromBuffer(buffer);    ID[Helper::StringLength(buffer)] = '\0';
	}

	Post** ReturnTimeline()
	{
		return Timeline;  // returning pointer of timelie 
	}


	void AddToTimeline(Post* post)  // This Function will add the post to OBJECT'S Timeline
	{
		if (Timeline == 0)
		{
			Timeline = new Post * [10];  // assigning maximum space
		}

		Timeline[NoOfTimelinePosts++] = post;
	}
	char* ReturnID() {
		return ID;
	}
	virtual void  PrintName()
	{
		cout << " kuch bhi " << endl;
	}
};


class PostContent
{
public:
	virtual char* ReturnActivityType()  // this is virtual function which will not be used but is overloaded through virtual
	{
		return 0;
	}

	virtual char* ReturnActivityName()
	{
		return 0;
	}
	virtual ~PostContent()
	{ }
};

class Activity : public PostContent
{
	char type;
	char* TypeOfActivity;
	char* value;

public:

	Activity()
	{
		type = 0;
		TypeOfActivity = 0;
		value = 0;
	}
	~Activity()
	{
		if (TypeOfActivity != 0)
		{
			delete TypeOfActivity;
		}
		if (value != 0)
		{
			delete value;
		}
	}
	void SetType(char number) // it will set the type of activity
	{


		if (number == '1')
		{
			char temp[] = "feeling";
			TypeOfActivity = new char[Helper::StringLength(temp) + 1];
			TypeOfActivity = Helper::GetStringFromBuffer(temp);

		}
		else if (number == '2')
		{
			char temp[] = "thinking about";
			TypeOfActivity = new char[Helper::StringLength(temp) + 1];
			TypeOfActivity = Helper::GetStringFromBuffer(temp);
		}

		else if (number == '3')
		{
			char temp[] = "making";
			TypeOfActivity = new char[Helper::StringLength(temp) + 1];
			TypeOfActivity = Helper::GetStringFromBuffer(temp);
		}

		else if (number == '4')
		{
			char temp[] = "celebrating";
			TypeOfActivity = new char[Helper::StringLength(temp) + 1];
			TypeOfActivity = Helper::GetStringFromBuffer(temp);

		}

	}

	void SetActivity(char buffer[])
	{

		value = new char[Helper::StringLength(buffer) + 1];
		value = Helper::GetStringFromBuffer(buffer);
	}

	char* ReturnActivityType()
	{
		return TypeOfActivity;
	}

	char* ReturnActivityName()
	{
		return value;
	}

};

class Pages : public Object  // inheriting object 
{
	char* PageName;
	int NoOfFollowers;
public:
	Pages()   // Constructor
	{
		PageName = 0;
	}
	Pages(ifstream& fin)
	{
		ReadDataFromFile(fin);
	}
	~Pages();

	void ReadDataFromFile(ifstream& fin)
	{
		char buffer[80];
		fin >> buffer;
		SetID(buffer);  // this will set ID in Object class 
		fin >> ws;
		fin.getline(buffer, 99);
		PageName = new char[Helper::StringLength(buffer) + 1];
		PageName = Helper::GetStringFromBuffer(buffer);    PageName[Helper::StringLength(buffer)] = '\0';
	}

	bool SearchPagebyID(char* str, char* substr)
	{
		if (Helper::Compare(str, substr) == 1)  return 1;  // Returning the Relevant Use 
	}

	//-----------------------Getter and Setters-------------------------

	char* GetPageName()
	{
		return PageName;
	}

	void PrintName()
	{
		cout << PageName;
	}
};



class Users : public Object  // inheriting object class 
{
	char* fname;
	char* lname;
	int NoOfFriend;
	int LikedPages;
	Users* friendlist[10];
	Pages* LikedPageList[10];
public:

	Users()   // Constructor 
	{
		fname = 0;
		lname = 0;
		LikedPages = 0;
		NoOfFriend = 0;
		for (int i = 0; i < 10; i++)
		{
			friendlist[i] = 0;
			LikedPageList[i] = 0;
		}

	}

	Users(ifstream& fin) // overloaded constructor
	{
		ReadDataFromFile(fin);
	}

	~Users();

	void ReadDataFromFile(ifstream& fin)  // For Inserting data for each user/object
	{
		char buffer[80];
		fin >> buffer;
		SetID(buffer);  // this will set ID in Object class 
		fin >> buffer;
		fname = new char[Helper::StringLength(buffer) + 1];
		fname = Helper::GetStringFromBuffer(buffer);    fname[Helper::StringLength(buffer)] = '\0';
		fin >> buffer;
		lname = new char[Helper::StringLength(buffer) + 1];
		lname = Helper::GetStringFromBuffer(buffer);    lname[Helper::StringLength(buffer)] = '\0';
	}
	bool SearchUserbyID(char* str, char* substr)
	{
		if (Helper::Compare(str, substr) == 1)
		{
			return 1;  // Returning the Relevant User
		}
	}

	void AddFriend(Users*& frienduser)
	{
		friendlist[NoOfFriend] = frienduser;  // Adding user into friend list of this object
		NoOfFriend++;
	}

	void AddPage(Pages*& PageID)
	{
		LikedPageList[LikedPages] = PageID;    // Adding Page into this object's followed page list
		LikedPages++;
	}

	void ViewFriendList()
	{
		for (int i = 0; i < NoOfFriend; i++)
		{
			cout << friendlist[i]->ReturnID() << "-- " << friendlist[i]->fname << " " << friendlist[i]->lname << endl;
		}
	}

	void ViewLikedPages()
	{
		for (int i = 0; i < LikedPages; i++)
		{
			cout << LikedPageList[i]->ReturnID() << " ";
			cout << LikedPageList[i]->GetPageName() << " " << endl;
		}
	}

	void PrintName()
	{
		cout << fname << " " << lname;
	}

	int ReturnNoOfFriends() { return NoOfFriend; }
	int ReturnNoOfLikedPages() { return LikedPages; }

	Users* ReturnFriendPointer(int i)
	{
		return friendlist[i];
	}
	Pages* ReturnPagePointer(int i)
	{
		return LikedPageList[i];
	}


};


class Comments
{
	char* CommentID;
	char* CommentContent;

	Object* CommentedBy;

public:
	void PrintCommentBy();
	char* ReturnCommentedText();
	Comments()
	{
		CommentID = 0;
		CommentContent = 0;

		CommentedBy = 0;
	}

	Comments(ifstream& fin, char buffer[])
	{

		fin >> buffer;

		SetCommentID(buffer);


	}

	~Comments()
	{


		if (CommentID != 0)
		{
			delete CommentID;
		}
		if (CommentContent != 0)
		{
			delete CommentContent;
		}

	}

	void SetCommentID(char bufferID[])
	{

		CommentID = new char[Helper::StringLength(bufferID) + 1];
		CommentID = Helper::GetStringFromBuffer(bufferID);    CommentID[Helper::StringLength(bufferID)] = '\0';
	}

	void SetCommentContent(const char bufferContent[])
	{
		CommentContent = new char[Helper::StringLength(bufferContent) + 1];
		CommentContent = Helper::GetStringFromBuffer(bufferContent);    CommentContent[Helper::StringLength(bufferContent)] = '\0';
	}

	void SetCommentBy(Users* User)
	{
		CommentedBy = User;
	}

	void SetUserPointer(Object* user)
	{
		CommentedBy = user;
	}
	void DisplayComment();


};

class Post
{
	char* PostID;
	Date SharedDate;   // date of the post by Date class 
	char* Text;
	Object* SharedBy;
	Object** LikedBy;
	int NoOfLikedBy;
	Comments** CommentsOnPost;
	int NoOfComments;
	PostContent* ContentOfPost;


public:
	void DisplayPost();
	virtual void DisplayTimelinedPost();
	void DisplayCustomTimelinedPosts();
	Post()
	{
		PostID = 0;
		Text = 0;
		NoOfLikedBy = 0;
		SharedBy = 0;
		LikedBy = 0;
		CommentsOnPost = 0;
	}
	Post(ifstream& fin) //overloaded Constructor
	{
		ReadDataFromFile(fin);
	}

	Post(Object* user, const char* content, const char* buffer)
	{
		PostID = new char[Helper::StringLength(buffer) + 1];
		PostID = Helper::GetStringFromBuffer(buffer);    PostID[Helper::StringLength(buffer)] = '\0';

		Text = new char[Helper::StringLength(content) + 1];
		Text = Helper::GetStringFromBuffer(content);    Text[Helper::StringLength(content)] = '\0';

		SharedBy = user; // Assigning the user who shares the post 
		NoOfLikedBy = 0;
		SharedDate = Date::PresentDate;  // Memory post shared date will be same as Present Dtae
		LikedBy = 0;
		CommentsOnPost = 0;
	}

	virtual ~Post()
	{
		if (Text != 0)
		{
			delete Text;
		}
		if (PostID != 0) delete PostID;

		if (CommentsOnPost != 0)
		{
			for (int i = 0; i < NoOfComments; i++)
			{
				delete CommentsOnPost[i];
			}
			delete CommentsOnPost;
		}
		if (ContentOfPost != 0) delete ContentOfPost;
		if (LikedBy != 0) delete LikedBy;
	}


	void ReadDataFromFile(ifstream& fin)
	{
		char buffer[80];
		fin >> buffer;

		PostID = new char[Helper::StringLength(buffer) + 1];
		PostID = Helper::GetStringFromBuffer(buffer);    PostID[Helper::StringLength(buffer)] = '\0';
		SharedDate.ReadDataFromFile(fin);  // Ye date ke members is object ke liye insert krdega 
		fin >> ws;
		fin.getline(buffer, 79);  // reading complete line 
		Text = new char[Helper::StringLength(buffer) + 1];
		Text = Helper::GetStringFromBuffer(buffer);    Text[Helper::StringLength(buffer)] = '\0';
	}


	bool SearchPostbyID(const char* str, const char* substr)
	{
		if (Helper::Compare(str, substr) == 1)
		{
			return 1;  // Returning the Relevant User
		}

	}

	void AllocateCommentsSpace()  // This will only Allocate space to Comments if it is Null pointer
	{
		if (CommentsOnPost == 0)
		{
			CommentsOnPost = new Comments * [10];
		}
	}

	void AddComment(Comments* cmnt)
	{
		if (CommentsOnPost == 0)
		{
			CommentsOnPost = new Comments * [10];
		}
		CommentsOnPost[NoOfComments++] = cmnt;
	}

	void AddPostContent(Activity* ptr)  // Will add the activity to the postcontent pointer in the Post class 
	{
		ContentOfPost = ptr;
	}



	void SetSharedBy(Object* temp)  // this will set the SharedBY Page or User 
	{
		SharedBy = temp;
	}

	void AddLikedBy(Object* temp) // This will add the objects in the array who have liked the post 
	{
		if (LikedBy == 0)
		{
			LikedBy = new Object * [10];
		}
		int flag = 0;
		for (int i = 0; i < NoOfLikedBy; i++)
		{
			if (LikedBy[i] == temp)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			LikedBy[NoOfLikedBy++] = temp;

	}

	void DisplayLikedObjects()
	{
		//cout << "Post " << ReturnID()<<" is liked by"<<endl;
		for (int i = 0; i < NoOfLikedBy; i++)
		{
			cout << LikedBy[i]->ReturnID() << " ";
			LikedBy[i]->PrintName();
			cout << endl;
		}
	}

	char* ReturnPostID()
	{
		return PostID;
	}

	Object* ReturnSharedBy()
	{
		return SharedBy;
	}

	void DisplayTimelinedMemory(Post* ptr)
	{
		cout << "\t"; SharedBy->PrintName(); cout << " shared a memory " << endl;
		cout << "Post Description: " << Text << endl;
		cout << "\t" << ptr->SharedDate.CalculateYear() << " years ago on this day " << endl;
		cout << "------------------------------------------------------------ " << endl;
	}

	int PostDateCalculate()
	{
		return SharedDate.CalculateYear();
	}

	void DisplayMemory()
	{

		cout << Text << endl;
		cout << "It is shared by " << SharedBy->ReturnID() << " ";
		SharedBy->PrintName();
		cout << endl;
	}

};

Object:: ~Object()
{
	if (ID != 0) delete ID;
	if (Timeline != 0)
	{

		for (int i = 0; i < NoOfTimelinePosts; i++)
		{
			delete Timeline[i];
		}

		delete Timeline;
	}

}

Pages::~Pages()   // Destructor
{
	if (PageName != 0)
	{
		delete PageName;
		PageName = 0;
	}
}

Users::~Users()   // Destructor
{

	if (fname != 0)
	{
		delete fname;
		fname = 0;
	}
	if (lname != 0)
	{
		delete lname;
		lname = 0;
	}


	for (int i = 0; i < 10; i++)
	{
		if (friendlist[i] != 0)
		{
			friendlist[i] = 0;
		}

		if (LikedPageList[i] != 0)
		{
			LikedPageList[i] = 0;
		}
	}
}



class Memory :public Post
{
	Post* OriginalPost;

public:
	Memory(Object* CurrentUser, const char* text, const char* PostID, Post* post) : Post(CurrentUser, text, PostID)
	{
		CurrentUser->AddToTimeline(this);
		OriginalPost = post;
	}
	~Memory()
	{

		OriginalPost = 0;
	}

	void DisplayPost()
	{
		cout << "We hope you enjoy looking back and sharing your memories on Facebook, from the most recent to those long ago. " << endl;
		cout << "On this Day " << endl;
		cout << OriginalPost->PostDateCalculate() << " years ago " << endl;
		OriginalPost->DisplayPost();

	}

	void DisplayTimelinedPost()
	{
		DisplayTimelinedMemory(OriginalPost);
		OriginalPost->DisplayTimelinedPost();
		cout << "------------------------------------------------------- " << endl;
	}
};

void Object::ViewCustomTimeline()
{
	for (int i = 0; i < NoOfTimelinePosts; i++)
	{
		Timeline[i]->DisplayCustomTimelinedPosts();
	}
}

void Object::ViewTimeline()
{
	for (int i = 0; i < NoOfTimelinePosts; i++) {
		Timeline[i]->DisplayTimelinedPost();
	}
}




void Post::DisplayPost()  // This will Display the Post 
{
	cout << "Time: ";
	if (SharedDate.CheckDate() == -1) { cout << " 1h " << endl; }
	else
	{
		SharedDate.DisplayDate();
		cout << endl;

	}

	if (ContentOfPost != 0) {
		SharedBy->PrintName();
		cout << " is " << ContentOfPost->ReturnActivityType() << " " << ContentOfPost->ReturnActivityName() << endl;
	}

	cout << "Post Description: " << Text << endl;
	cout << "It is shared by " << SharedBy->ReturnID() << " ";
	SharedBy->PrintName();
	cout << endl;
	cout << "It is liked by : " << endl;
	if (LikedBy)
		DisplayLikedObjects();
	cout << endl;
	cout << "Comments on Post are " << endl;
	for (int i = 0; i < NoOfComments; i++)
	{
		CommentsOnPost[i]->DisplayComment();
		cout << endl;
	}
	cout << endl;


}


void Post::DisplayCustomTimelinedPosts()
{
	if (SharedDate.CompareDate() == 1)
	{
		cout << endl;
		SharedBy->PrintName();
		if (ContentOfPost != 0)cout << " is " << ContentOfPost->ReturnActivityType() << " " << ContentOfPost->ReturnActivityName() << endl;

		if (SharedDate.CheckDate() != 0)
		{
			if (SharedDate.CheckDate() == -1)
			{
				cout << "(Today) ";
			}
			else cout << "(" << SharedDate.CheckDate() << " days ago )";
		}
		else
			SharedDate.DisplayDate(); cout << endl;
		cout << Text;
		cout << endl;
		cout << "Comments: " << endl;
		for (int i = 0; i < NoOfComments; i++)
		{
			CommentsOnPost[i]->PrintCommentBy();
			cout << ": " << CommentsOnPost[i]->ReturnCommentedText() << endl;
		}
		cout << endl;
	}
}

void Post::DisplayTimelinedPost()
{
	cout << endl;
	SharedBy->PrintName();
	if (ContentOfPost != 0)cout << " is " << ContentOfPost->ReturnActivityType() << " " << ContentOfPost->ReturnActivityName() << endl;

	if (SharedDate.CheckDate() == 1) cout << "(1h) ";
	else
		SharedDate.DisplayDate(); cout << endl;
	cout << Text;
	cout << endl;
	cout << "Comments: " << endl;
	for (int i = 0; i < NoOfComments; i++)
	{
		CommentsOnPost[i]->PrintCommentBy();
		cout << ": " << CommentsOnPost[i]->ReturnCommentedText() << endl;
	}
	cout << endl;
}

void Comments::DisplayComment()
{
	CommentedBy->PrintName();
	cout << ": ";
	cout << CommentContent;
}

void Comments::PrintCommentBy()
{
	if (CommentedBy != 0)
		CommentedBy->PrintName();
}

char* Comments::ReturnCommentedText()
{
	return CommentContent;
}

class Controller
{
	static int NoOfUsers;
	static int NoOfPages;
	static int NoOfPosts;
	Users** AllUsers;  // Associating with the User class.
	Pages** AllPages;
	Post** AllPosts;
	Date CurrentDate;
	Users* CurrentUser;  // This will point to the current user set by us 

public:

	Controller()  // Constructor
	{
		AllUsers = 0;
		AllPages = 0;
		AllPosts = 0;
		CurrentUser = 0;
	}

	~Controller()  // Destructor
	{
		if (AllUsers != nullptr)
		{
			for (int i = 0; i < NoOfUsers; i++)
			{
				delete AllUsers[i]; // Delete each Users object
			}
			delete[] AllUsers; // Delete the array of pointers
			AllUsers = nullptr;
		}

		if (AllPages != nullptr)
		{
			for (int i = 0; i < NoOfPages; i++)
			{
				delete AllPages[i]; // Delete each Pages object
			}
			delete[] AllPages; // Delete the array of pointers
			AllPages = nullptr;
		}
		if (AllPosts != nullptr)
		{
			delete[] AllPosts;  // Only outer layer 

		}
	}

	void LoadData(ifstream& fin)   // This will accomplish major tasks of Controller class
	{
		StoreData(fin);
		LoadAllComments(fin);
		LinkUsersandPages(fin);
		LoadAllActivities(fin);

	}


	void StoreData(ifstream& fin)  // This will enter all the data 

	{
		fin >> NoOfUsers; // Getting total number of users
		AllUsers = new Users * [NoOfUsers];
		for (int i = 0; i < NoOfUsers; i++)
		{
			AllUsers[i] = new Users(fin);
		}
		fin >> NoOfPages;
		AllPages = new Pages * [NoOfPages];
		for (int i = 0; i < NoOfPages; i++)
		{
			AllPages[i] = new Pages(fin);
		}
		fin >> NoOfPosts;
		AllPosts = new Post * [NoOfPosts];
		for (int i = 0; i < NoOfPosts; i++)
		{
			AllPosts[i] = new Post(fin);

			Object* temp = FindPointerOfSharedByObject(fin);

			if (temp != 0)
			{
				temp->AddToTimeline(AllPosts[i]);
				AllPosts[i]->SetSharedBy(temp);
			}




			while (1)
			{
				Object* temp2 = FindPointerOfLikedBy(fin);
				if (temp2 == 0) break;   // this will break when -1 is encountered, temp2 is zero when -1 is encountered 
				else if (temp2 != 0)
				{
					AllPosts[i]->AddLikedBy(temp2);   // setting LikedBy array 

				}
			}


		}
	}

	void LoadAllComments(ifstream& fin)
	{
		int NoOfComments;
		fin >> NoOfComments;

		for (int i = 0; i < NoOfComments; i++)
		{
			char buffer[80];
			Comments* ptr = new Comments(fin, buffer);
			fin >> buffer;
			Post* temp = 0;
			temp = SearchforPostPointer(buffer);

			if (temp != 0)
			{
				temp->AddComment(ptr); // This will add Comment to the post
			}

			fin >> buffer;
			Object* temp2 = 0;
			temp2 = SearchforUserPointer(buffer);
			if (temp2 != 0) ptr->SetUserPointer(temp2);   // this will store the obj who commented 
			temp2 = SearchforPagePointer(buffer);
			if (temp2 != 0) ptr->SetUserPointer(temp2); // This will store obj of who commented

			fin >> ws;
			fin.getline(buffer, 79);  // reading complete line 

			ptr->SetCommentContent(buffer);
		}
	}

	void SetCurrentDate(int d = 0, int m = 0, int y = 0)  // This will set current date 
	{
		CurrentDate.SetValues(d, m, y);
	}

	void AddCommentOnPost(const char* postid, const char comment[]) // this will add our Custom comment to our desired post
	{

		Post* CurrentPost = SearchforPostPointer(postid);
		Comments* NewComment = new Comments;
		NewComment->SetCommentContent(comment);
		char newid[] = "c12";
		NewComment->SetCommentID(newid);
		NewComment->SetCommentBy(CurrentUser);
		CurrentPost->AddComment(NewComment);
	}

	Object* FindPointerOfSharedByObject(ifstream& fin)  // This will find the Sharedby pointer by the Object ID
	{
		char string[80];
		fin >> string;
		if (string[0] == '-' && string[1] == '1')  return 0;
		for (int i = 0; i < NoOfUsers; i++)
		{
			if (AllUsers[i]->SearchUserbyID(AllUsers[i]->ReturnID(), string) == 1)
			{
				return AllUsers[i];
			}
		}

		for (int i = 0; i < NoOfPages; i++)
		{
			if (AllPages[i]->SearchPagebyID(AllPages[i]->ReturnID(), string) == 1)
			{
				return AllPages[i];
			}
		}
		return 0;
	}

	Object* FindPointerOfLikedBy(ifstream& fin)   // This will find the object who has liked a Post
	{

		return FindPointerOfSharedByObject(fin);
	}


	Users* SearchforUserPointer(char* buffer)   // This will search for User pointer corresponding to given id 
	{
		for (int i = 0; i < NoOfUsers; i++)
		{
			if (AllUsers[i]->SearchUserbyID(AllUsers[i]->ReturnID(), buffer) == 1)   // if match then preset nuser mil gya
			{
				return AllUsers[i];
			}
		}
		return 0;
	}

	Pages* SearchforPagePointer(char* buffer) // same functionality as SearchforUserPointer
	{

		for (int i = 0; i < NoOfPages; i++)
		{
			if (AllPages[i]->SearchPagebyID(AllPages[i]->ReturnID(), buffer) == 1)   // if match then preset nuser mil gya
			{
				return AllPages[i];
			}
		}
		return 0;
	}

	Post* SearchforPostPointer(const char* buffer) // Same as SearchforUserPointer 
	{
		for (int i = 0; i < NoOfPosts; i++)
		{
			if (AllPosts[i]->SearchPostbyID(AllPosts[i]->ReturnPostID(), buffer) == 1)
			{
				return AllPosts[i];    // means relevant page found 
			}
		}
		return 0;
	}

	void LinkUsersandPages(ifstream& fin)  // Lining Liked Pages and Friends of a specific User 
	{
		while (1)
		{
			char buffer[80];
			fin >> buffer;

			if (buffer[1] == '1' && buffer[0] == '-')	 break;
			Pages* PresentPage = 0;  // This will store the current page on which working is to be done 
			PresentPage = SearchforPagePointer(buffer);
			Users* PresentUser = 0;
			PresentUser = SearchforUserPointer(buffer);

			while (1)
			{
				fin >> buffer;
				if (buffer[1] == '1' && buffer[0] == '-') break;

				Users* temp = SearchforUserPointer(buffer);
				PresentUser->AddFriend(temp);    // Adding friend to the friend list of present user 
			}
			while (1)
			{
				fin >> buffer;
				if (buffer[1] == '1' && buffer[0] == '-') break;
				Pages* temp1 = SearchforPagePointer(buffer);
				PresentUser->AddPage(temp1);   // Adding liked page to the present user 
			}

		}
	}

	void Extra(Object* temp)
	{
		temp->ViewTimeline();
	}


	Users* SetCurrentUSer(char buffer[])    // This will return pointer of the current user 
	{
		for (int i = 0; i < NoOfUsers; i++)
		{
			if (AllUsers[i]->SearchUserbyID(AllUsers[i]->ReturnID(), buffer) == 1)   // if match then preset nuser mil gya
			{
				CurrentUser = AllUsers[i];
				return AllUsers[i];
			}
		}
		return 0;
	}

	void LikeThePage(char* string) // It wil like the page through given id 
	{

		for (int i = 0; i < NoOfPosts; i++)
		{
			if (AllPosts[i]->SearchPostbyID(AllPosts[i]->ReturnPostID(), string) == 1)
			{
				AllPosts[i]->AddLikedBy(CurrentUser);
			}
		}

	}

	Object* SetCurrentObject(char buffer[])    // This will return pointer of the current user 
	{
		for (int i = 0; i < NoOfUsers; i++)
		{
			if (AllUsers[i]->SearchUserbyID(AllUsers[i]->ReturnID(), buffer) == 1)   // if match then preset nuser mil gya
			{
				CurrentUser = AllUsers[i];
				return AllUsers[i];
			}
		}
	}

	Pages* ReturnPagePointer(char buffer[])
	{
		for (int i = 0; i < NoOfPages; i++)
		{
			if (AllPages[i]->SearchPagebyID(AllPages[i]->ReturnID(), buffer) == 1)   // if match then preset nuser mil gya
			{
				//CurrentUser = AllUsers[i];
				return AllPages[i];
			}
		}
		return 0;
	}

	void DetailedView(Users* CurrentUser) // Detailed View of User Information
	{
		cout << endl;
		cout << "---------------------------------------------------------------------------------------------------------------- " << endl;
		cout << "Command: Display Friend List " << endl;
		cout << "---------------------------------------------------------------------------------------------------------------- " << endl;

		cout << "Friends List is: " << endl;
		CurrentUser->ViewFriendList();
		cout << endl << endl;
		cout << "---------------------------------------------------------------------------------------------------------------- " << endl;

		cout << "Command : Display Liked Pages List " << endl;
		cout << "---------------------------------------------------------------------------------------------------------------- " << endl;

		CurrentUser->ViewLikedPages();
	}

	void PostLikedUser(char* string)
	{
		for (int i = 0; i < NoOfPosts; i++)
		{
			if (AllPosts[i]->SearchPostbyID(AllPosts[i]->ReturnPostID(), string))
			{
				Post* PresentPage = AllPosts[i];
				PresentPage->DisplayLikedObjects();
			}
		}
	}



	void ViewLikedList(char* string)
	{
		for (int i = 0; i < NoOfPosts; i++)
		{
			if (AllPosts[i]->SearchPostbyID(AllPosts[i]->ReturnPostID(), string) == 1)
			{
				Post* PresentPage = AllPosts[i];
				PresentPage->DisplayPost();
			}
		}

	}


	void LoadAllActivities(ifstream& fin)  // It will load all the activities
	{
		int NoOfActivities;
		fin >> NoOfActivities;

		for (int i = 0; i < NoOfActivities; i++)
		{
			Activity* ptr = new Activity;
			char buffer[80];
			fin >> buffer;
			Post* Postptr = SearchforPostPointer(buffer);
			Postptr->AddPostContent(ptr);
			fin >> buffer;
			ptr->SetType(buffer[0]);
			fin >> ws;

			fin.getline(buffer, 79);
			ptr->SetActivity(buffer);

		}

	}


	void DisplayHomePage(Users* PresentUser) // current user ka HomePage
	{
		// first timeline of Current User 
		PresentUser->ViewCustomTimeline();
		int NoOfFriends = PresentUser->ReturnNoOfFriends();

		for (int i = 0; i < NoOfFriends; i++)
		{
			Users* tempPtr = PresentUser->ReturnFriendPointer(i);
			tempPtr->ViewCustomTimeline();
		}

		int NoOfPagesLiked = PresentUser->ReturnNoOfLikedPages();

		for (int i = 0; i < NoOfPagesLiked; i++)
		{
			Pages* tempPtr = PresentUser->ReturnPagePointer(i);
			tempPtr->ViewCustomTimeline();
		}
	}


	void Functioning()
	{
		cout << "--------------------------------------------------------------------------------------------------------------- " << endl;
		cout << "Command: Set Current Date 17/04/2024 " << endl;
		cout << "--------------------------------------------------------------------------------------------------------------- " << endl;
		Date::SetPresentDate(18, 4, 2024);    // Setting up Current Date

		cout << "Current Date 18/04/2024 " << endl << endl;
		cout << "--------------------------------------------------------------------------------------------------------------- " << endl;
		cout << "Command : Set Current User " << endl;
		cout << "--------------------------------------------------------------------------------------------------------------- " << endl;

		char Id[] = "u7";

		Users* PresentUser = SetCurrentUSer(Id);

		if (PresentUser == 0)
		{
			throw exception("Invalid user!");
		}


		cout << "                     Current user is " << PresentUser->ReturnID() << " " << endl;
		//cout << "--------------------------------------------------------------------------------------------------------------- " << endl<<endl;
		PresentUser->PrintName();
		cout << endl << endl;
		DetailedView(PresentUser);
		cout << endl;

		cout << endl;
		cout << "---------------------------------------------------------------------------------------------------------------- " << endl;
		cout << "Command : Set Current Post " << endl;
		cout << "--------------------------------------------------------------------------------------------------------------- " << endl;

		char PostID[] = "post10";
		Post* CurrentPost = SearchforPostPointer(PostID);
		if (CurrentPost == 0)
		{
			throw exception("Invalid Post id ");
		}
		CurrentPost->DisplayPost();
		cout << endl << endl;
		cout << "--------------------------------------------------------------------------------------------------------------- " << endl;
		cout << "Command: Add Like to " << PostID << " by Current User" << endl;
		cout << "--------------------------------------------------------------------------------------------------------------- " << endl;
		LikeThePage(PostID);

		ViewLikedList(PostID);
		cout << endl << endl;



		cout << "---------------------------------------------------------------------------------------------------------------- " << endl;
		cout << "Command: View Timeline of Current User " << endl;
		cout << "---------------------------------------------------------------------------------------------------------------- " << endl;
		PresentUser->ViewTimeline();
		cout << endl << endl;
		//char Comment[] = "Thanks!";
		cout << "---------------------------------------------------------------------------------------------------------------- " << endl;
		cout << "Command: Add Custom Comment to a post through custom post id " << endl;
		cout << "---------------------------------------------------------------------------------------------------------------- " << endl;
		AddCommentOnPost("post4", "Ye hai mera Custom Comment");
		CurrentPost = SearchforPostPointer("post4");
		CurrentPost->DisplayPost();
		CurrentPost = SearchforPostPointer("post10");
		cout << endl << endl;

		char Pageid[] = "p9";
		cout << "---------------------------------------------------------------------------------------------------------------- " << endl;
		cout << "Command: Display Timeline of Page(" << Pageid << ")" << endl;
		cout << "---------------------------------------------------------------------------------------------------------------- " << endl;
		Pages* CurrentPage = ReturnPagePointer(Pageid);
		if (CurrentPage == 0)
		{
			throw exception("Invalid Page Name");
		}

		CurrentPage->ViewTimeline();
		cout << endl << endl;

		cout << "------------------------------------------------------------------------------------------------------------- " << endl;
		cout << "Command: Display Home Page of Current User " << endl;
		cout << "---------------------------------------------------------------------------------------------------------------- " << endl;
		DisplayHomePage(PresentUser);
		cout << endl << endl;
		char* newpostid = Helper::CreationOfPostID("post", NoOfPosts);  // this will create new postid
		cout << "---------------------------------------------------------------------------------------------------------------- " << endl;
		cout << "Command: Display Memory Post: " << endl;
		cout << "---------------------------------------------------------------------------------------------------------------- " << endl;

		Memory* ptr = new Memory(PresentUser, "Can't believe that I have done PHD in it ", newpostid, CurrentPost);
		ptr->DisplayPost();
		cout << endl << endl;
		cout << "--------------------------------------------------------------------------------------------------------------- " << endl;
		cout << "Command: View Timeline " << endl;
		cout << "---------------------------------------------------------------------------------------------------------------- " << endl;

		PresentUser->ViewTimeline();
		cout << endl;
	}


};

int Controller::NoOfUsers = 0; // initializing static variable
int Controller::NoOfPages = 0;
int Controller::NoOfPosts = 0;

int main()
{

	{

		ifstream fin("Userslist.txt");
		if (!fin.is_open()) {
			cout << "Error opening the file." << endl;
			return 1;
		}


		//	 We shall access everything through controller class
		Controller facebook;
		facebook.LoadData(fin);   // This will load eah and every piece of data
		facebook.Functioning();
		fin.close();
		cout << endl;

	}





}