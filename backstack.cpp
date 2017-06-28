#include <string>
#include <sstream>
#include <iostream>

#include <backward.hpp>
using namespace backward;

struct S {

	void wards_backtrace1() {
		StackTrace st; st.load_here(1);
		Printer p; p.print(st);
	}
	void wards_backtrace2() {
		StackTrace st; st.load_here(32);

		TraceResolver tr; tr.load_stacktrace(st);
		for (size_t i = 0; i < st.size() ; ++i) {
			ResolvedTrace trace = tr.resolve(st[i]);
			std::cout << "#" << i
				<< " " << trace.object_filename
				<< " " << trace.object_function
				<< " [" << trace.addr << "]"
			<< std::endl;
		}
	}
	void wards_backtrace3() {
		StackTrace st; st.load_here(1000);
		Printer p;
		p.color_mode = ColorMode::always;
		p.object = true;
		p.address = true;
		p.print(st, stderr);
	}

	void wards_backtrace4() {

		std::ostringstream oss;
		StackTrace st; st.load_here(1000);
		Printer p;
		p.color_mode = ColorMode::always;
		p.object = true;
		p.address = true;
		p.print(st, oss);

		std::cout << oss.str();
	}
};

void foo2() {
	S lala;
	lala.wards_backtrace1();
}
void foo3() {
	S lala;
	lala.wards_backtrace2();
}
void foo4() {

	S lala;
	lala.wards_backtrace3();
}

void collect_trace(StackTrace& st) {
	st.load_here();
}

void foo5() {
	StackTrace st;
	collect_trace(st);

	Printer printer;
	printer.print(st, stdout);
}

void foo6() {

	S lala;
	lala.wards_backtrace4();
}


int main() {

	std::cout << "-----------------------------------------------------------------------------------------------------------" << "\n\n";
	std::cout << "backward-cpp STACKTRACE 1" << "\n\n";
	foo2();

	std::cout << "-----------------------------------------------------------------------------------------------------------" << "\n\n";
	std::cout << "backward-cpp STACKTRACE 2" << "\n\n";
	foo3();

	std::cout << "-----------------------------------------------------------------------------------------------------------" << "\n\n";
	std::cout << "backward-cpp STACKTRACE 3" << "\n\n";
	foo4();

	std::cout << "-----------------------------------------------------------------------------------------------------------" << "\n\n";
	std::cout << "backward-cpp STACKTRACE 4" << "\n\n";
	foo5();

	std::cout << "-----------------------------------------------------------------------------------------------------------" << "\n\n";
	std::cout << "backward-cpp STACKTRACE 5 streams" << "\n\n";
	foo6();
}
