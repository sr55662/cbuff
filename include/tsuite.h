#pragma once

#include<cstdio>
#include<string>
#include<map>
#include<vector>
#include<type_traits>
#include<typeinfo>

#ifdef __GNUG__
#include<cxxabi.h>
#include<cstdlib>
#endif


#define REGISTER_TEST(testName) registerTest(#testName, &subclass_t::testName)
#define ASSERT_OR_FAIL(expr) { if (!(expr) \
	{notifyTestFailed(__LINE__, #expr); return false; }}

#define SUCCEED() {return true;}

template<typename TSubclass>
class TSuite
{
public:
	static void notifyTestFailed(int line, const char* expr)
	{
		std::printf(" FAILED!\n ******* Assertion failed (line %d) %s\n\n"
					,line
					,expr
					);
	}

	bool validateTestName(std::string const& which) const
	{
		return testMap.find(which) != testMap.end();
	}

	void getAllTestNames(std::vector<std::string>& names) const
	{
		for(auto it = testMap.cbegin(); it != testMap.cend(); ++it) {
			names.push_back(it->first);
		}

	}

	bool run(unsigned int iterations=1)
	{
		bool success = true;
		for(auto it  =  testVec.cbegin(); it !=testVec.cend(); ++it) {
			if(!execTest(*it, iterations)) {
				success = false;
			}
		}

		return success;
	}


private:
	using subclass_t = TSubclass;

	void register_test(const char* name, bool (subclass_t::* method)())
	{
		testVec.push_back(std::make_pair(std::string(name), method));
		testMap[std::string(name)] =  method;
	}
	
	bool execTest(std::pair<std::string, bool(subclass_t::*)()> const& testRef,
				  unsigned int iterations)
	{
		std::printf("%s::%s... \n",
					demangle_type_name(typeid(subclass_t).name()).c_str(),
					testRef.first.c_str());

		bool result = true;
		for(unsigned int i = 0; i != iterations; ++i) {
			if(!(static_cast<subclass_t*>(this)->*testRef.second)()) {
				result = false;
				break;
			}
		}

		if(result) {
			std::printf("	passed\n\n");
		}
		else {
			std::printf("	FAILED!\n\n");
		}

		return result;
	}

protected:

	static std::string demangle_type_name(const char *name)
	{
#ifdef __GNUG__
		int status = -4;
		char* res = abi::__cxa_demangle(name, nullptr, nullptr, &status);

		const char* const demangled_name = (status == 0) ? res : name;
		std::string ret(demangled_name);

		std::free(res);
		return ret;
#else
		return name;
#endif
	}

	std::vector<std::pair<std::string, bool (TSubclass::*)()> > testVec;
	std::map<std::string, bool (TSubclass::*)()> testMap;
};

