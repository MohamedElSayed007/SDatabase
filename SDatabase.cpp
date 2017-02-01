/*
 * SDatabase.cpp
 *
 *      Author: Mohamed El Sayed
 *      email : m.elsayed4420@gmail.com
 *      lowlevelcode.blogspot.com
 */


#include "SDatabase.h"

string SDatabase::reader(const string path)
{

	if(check_db_init()==false && first_time == true)
	{
		cout<<"SDatabase.creatDB function is not initialized, SDatabase will generate a file called sdb_d.txt and use it as a database.\n";
		first_time = false;
	}
		ifstream read;
			string text;
			read.open(path.c_str());
			if(read.is_open())
			{
				while(!read.eof())
				{
					getline(read,text);
				}

				read.close();
			}

		return text;
}

void SDatabase::createDB(string dbName_)
{
	ifstream read;

	string text;
	read.open(dbName_.c_str());
	if(read.is_open())
	{
		while(!read.eof())
		{
			getline(read,text);
		}

		read.close();
	}


	ofstream write;
	write.open(dbName_.c_str());
	write<<text;
	write.close();


	dbName = dbName_;
}

bool SDatabase::exists(const string id)
{
	string text = reader(dbName);
	string::size_type check = text.find(id);
	if(check==string::npos)
	return false;
	else
	return true;
}

void SDatabase::writer(string data)
{
	string text = reader(dbName);
	ofstream write;
	write.open(dbName.c_str());
	write<<text<<data;
	write.close();
}

bool SDatabase::addNew()
{
		string data, temp;

		for(int loop = 0; loop < entry_count; loop++)
		{
			temp = temp+entries[loop];
		}
		if((temp.find(';')!=string::npos) || (temp.find('%')!=string::npos))
		{
				return false;
		}
		if(enable_duplication==true)
		{
			for(int i = 0; i < entry_count; i++)
			{
				data = data+entries[i]+'%';
			}
			data=data+';';
			writer(data);

			return true;
		}
		else if(enable_duplication==false)
		{
			if(exists(entries[0])==true)
				return false;
			else
			{
				for(int i = 0; i < entry_count; i++)
				{
					data = data+entries[i]+'%';
				}

				data=data+';';
				writer(data);

				return true;
			}
		}
		delete [] entries;
}

int SDatabase::viewAll()
{

string data = reader(dbName);

if(data.find(';')==string::npos){
	return -1;
}
else
{
	vector<string> rows;
	string::size_type i = 0;
	string::size_type colon = data.find(';');
	while(colon != string::npos)
	{
		rows.push_back(data.substr(i, colon-i));
		i = ++colon;
		colon = data.find(';', colon);

		if(colon == string::npos)
			rows.push_back(data.substr(i, data.length()));	
	}
	for(unsigned int rows_count = 0; rows_count < rows.size(); rows_count ++)
	{
		vector<string> elements;
		string::size_type i2 = 0;
		string::size_type perc = rows[rows_count].find('%');
		while(perc != string::npos)
		{
			elements.push_back(rows[rows_count].substr(i2, perc-i2));
			i2 = ++perc;
			perc = rows[rows_count].find('%',perc);
			if(perc==string::npos)
				elements.push_back(rows[rows_count].substr(i2,rows[rows_count].length()));
		}
		for (unsigned int count =0; count<elements.size(); count++)
		{
			cout<<elements[count]<<endl;
		}
		cout<<endl;
	}

}
	return 0;
}

bool SDatabase::searchById(const string id)
{
	string result;
	string data = reader(dbName);
	if (id=="") return false;
	string::size_type get = data.find(id);
	if(get==string::npos) {return false;}
	else
	{
		string temp = data.substr(get, data.length());
		get = temp.find(id);
		string::size_type colon = temp.find(';');
		result = temp.substr(get, colon);
	}
	vector<string> result_vector;
	string::size_type i = 0;
	string::size_type colon_pos = result.find('%');
	while(colon_pos!=string::npos)
	{
		result_vector.push_back(result.substr(i, colon_pos-i));
		i=++colon_pos;
		colon_pos = result.find('%', colon_pos);
		if(colon_pos==string::npos)
			result_vector.push_back(result.substr(i, result.length()));
	}
	for(unsigned int count = 0; count < result_vector.size(); count++)
	{
		cout<<result_vector[count]<<endl;
	}

	return true;
}

bool SDatabase::deleteById(const string id)
{
	ofstream append;
	string data, left, right, temp;
	data = reader(dbName);
	if(id=="") return false;

	string::size_type get = data.find(id);
	if(get==string::npos){return false;}
	else
	{
		right = data.substr(0,get);
		temp = data.substr(get, data.length());
		string::size_type colon = temp.find(';');
		left = temp.substr(colon+1, temp.length());
		data=right+left;
		append.open(dbName.c_str());
		append << data;
		append.close();
		return true;
	}
}

void SDatabase::clear()
{
	ofstream clear;
	clear.open(dbName.c_str());
	clear << "";
	clear.close();

}

bool SDatabase::check_db_init()
{
	if(dbName=="sdb_d.txt")
		return false;
	else
		return true;
}
