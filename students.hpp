#ifndef STUDENTS_HPP
#define STUDENTS_HPP

#include<string>


class student
{
	private:
			std::string _name;
			float _score;
			std::string _branch;
			int _std;
			static int sciCnt;
			static int artCnt;
			static int sciPassCnt;
			static int artPassCnt;
	public:
			student(std::string name,float score,std::string branch,int std):_name(name),_score(score),_branch(branch),_std(std)
			{
				if(_branch == "science")
				{	
					sciCnt++;
					if(_score >= 35)
						sciPassCnt++;	
				}
				else
				{
					artCnt++;

					if(_score >= 35)
						artPassCnt++;

				}
			}
			static int getSciCnt()
			{
				return sciCnt;

			}
			static int getArtCnt()
			{
				return artCnt;
			}
			static float getSciPassPercent()
			{	
				float res = (float)sciPassCnt / sciCnt ;;
				return res*100 ;
			} 
	
			static float getArtPassPercent()
			{	
				float res = (float)artPassCnt / artCnt ;;
				return res*100 ;
			}
			std::string getName() const{ return _name; } 
			std::string getBranch() const { return _branch; }
			int getCls() const { return _std; }
			float getScore() const { return _score; }
			bool operator==(const student& other)
			{
				if(_name == other._name)
					return true;
				return false;
			}
};

int student::sciCnt=0;
int student::artCnt=0;
int student::sciPassCnt=0;
int student::artPassCnt=0;

#endif
