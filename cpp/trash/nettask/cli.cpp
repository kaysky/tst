#include "cform.hpp"

using namespace std;
using namespace kki;


int main(int argc, char* argv[])
{
	QApplication app(argc, argv);

	DlgForm dlg;
	dlg.show();

	return app.exec();
}
