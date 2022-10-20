#include <iostream>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/json_parser.hpp>

using boost::property_tree::ptree;

//class for XML writing
class XMLElem
{
public:
	int x;
	int y;
	int z;
	std::string str;
	XMLElem(int _id1, int _id2, int _id3, std::string _str) : x(_id1), y(_id2), z(_id3), str(_str) {}
};

int main()
{
	//read from XML file
	ptree pt;

	try
	{
		read_xml(".\\for_read.xml", pt);
	}
	catch (const std::exception&)
	{
		std::cout << "Bad path\n";
		return 1;
	}

	try
	{
		int i = 0;
		for (const auto& child : pt.get_child("localinfo.playerinfo"))
		{
			std::cout << "Node name: " << child.first << std::endl;
			std::cout << "NickName value: " << child.second.get<std::string>("<xmlattr>.nickname") << std::endl;
			std::cout << "Password value: " << child.second.get<std::string>("<xmlattr>.pass") << std::endl;
			std::cout << "isOnline value: " << child.second.get<int>("<xmlattr>.isOnline") << std::endl;
			std::cout << "\n";
			++i;
		}
		std::cout << "Total users: " << i << "\n";
	}
	catch (const std::exception&)
	{
		std::cout << "Bad data\n";
		return 1;
	}


	//write XML file
	//witout exceptions
	XMLElem* elem[3] = { new XMLElem(1,2,3, "Red_point"), new XMLElem(-12,0,-3, "Blue_point"), new XMLElem(155,12,90, "Green_point") };
	ptree pt_for_write;

	ptree mychild;
	for (size_t i = 0; i < 3; ++i)
	{
		mychild.add("X", elem[i]->x);
		mychild.add("Y", elem[i]->y);
		mychild.add("Z", elem[i]->z);
		mychild.add("point_color", elem[i]->str);
		pt_for_write.add_child("Graphics.XML_Element", mychild);
		mychild.clear();
	}
	write_xml("for_write.xml", pt_for_write);
	write_json("for_write.json", pt_for_write);

	for (size_t i = 0; i < 3; i++)
	{
		delete elem[i];
	}

	return 0;
}