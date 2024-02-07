#include <string>
#include <vector>
#include "tinyxml2.h"

using namespace tinyxml2;

struct discord_embed_struct_create {
	std::string token;
	std::string message_optional;
	std::string embed_name;
	std::string embed_description;
	std::string embed_color;
	std::vector<std::string> fields_name;
	std::vector<std::string> fields_description;
	std::vector<std::string> fields_inline;
};
discord_embed_struct_create main_struct_one;
void loader() {
	//loads needed information to data struct
}
void editor() {
}
void saver() {
}
void sender() {
}
void testing() {
	tinyxml2::XMLDocument xmlDoc;

	XMLNode* pRoot = xmlDoc.NewElement("Root");

	xmlDoc.InsertFirstChild(pRoot);

	//int values
	XMLElement* pElement = xmlDoc.NewElement("IntValue");
	pElement->SetText(10);
	pRoot->InsertEndChild(pElement);

	pElement = xmlDoc.NewElement("FloatValue");
	pElement->SetText(0.5f);

	pRoot->InsertEndChild(pElement);

	XMLError eResult = xmlDoc.SaveFile("SavedData.xml");
}
int main(int argc, char* argv[]) {
	testing();
	return 0;
}
