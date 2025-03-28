#pragma once

namespace use_cases {
class UseCases;
}

namespace infrastructure {

class Console {
public:
	Console(use_cases::UseCases& useCases);

	void run();

private:
	use_cases::UseCases& m_useCases;
};

}
