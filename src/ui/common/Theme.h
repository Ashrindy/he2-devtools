#pragma once

struct Theme {
	const char* name;
	void (*Load)();

	static constexpr size_t themeCount{ 8 };
	static Theme themes[themeCount];
};
