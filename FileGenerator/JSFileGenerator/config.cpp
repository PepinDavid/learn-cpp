#include <stdio.h>
#include <string>

const std::string PATH_WHERE_FILES = "/home/david/perso/dev/learn-cpp/FileGenerator/JSFileGenerator";
std::string HTML = "<template name=\"{{tpl}}\">\n</template>";
std::string JS = "/**********************************************\n\n\t{{tpl}}.js\t{{Name}}\t{{date}}\n\n"+
	"**********************************************/\n"+
	"import { Meteor }           from    'meteor/meteor';\n import { Template }         from    'meteor/templating';\n\n"+
	"import 								'/client/imports/ui/{{tpl}}.html';\n"+
	"//---------------------------------------------\n\n\n"+
	"Template.{{tpl}}.onCreate(function(){\n\tvar self = this;\n});\n"+
	"Template.{{tpl}}.helpers({\n\n});\n"+
	"Template.{{tpl}}.onRendered(function(){\n\tvar self = this;\n});\n"+
	"Template.{{tpl}}.events({\n\n});\n";
const std::string TPL = "{{tpl}}";
const std::string NAME = "{{Name}}";
const std::string DATE = "{{date}}";