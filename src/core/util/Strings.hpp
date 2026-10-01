#pragma once
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <unordered_map>

namespace YimMenu
{
	inline std::string LocalizeMenuText(const std::string& input)
	{
		if (input.empty())
			return {};

		static const std::unordered_map<std::string, std::string> translations = {
		    {"Self", "自我"},
		    {"Vehicle", "载具"},
		    {"Teleport", "传送"},
		    {"Network", "网络"},
		    {"Players", "玩家"},
		    {"World", "世界"},
		    {"Recovery", "恢复"},
		    {"Settings", "设置"},
		    {"Debug", "调试"},
		    {"Main", "主菜单"},
		    {"Globals", "全局"},
		    {"Movement", "移动"},
		    {"Tools", "工具"},
		    {"Special Ability", "特殊能力"},
		    {"Wanted", "通缉"},
		    {"Hotkey", "热键"},
		    {"Close", "关闭"},
		    {"Unknown!", "未知!"},
		    {"Unknown", "未知"},
		    {"No hotkey assigned", "未分配热键"},
		    {"Press any button...", "按任意键..."},
		    {"Press any registered key to remove", "按任意已注册按键以移除"},
		    {"Hover over the command name to change its hotkey", "将鼠标悬停在命令名上以修改热键"},
		    {"Enter a keystroke", "输入按键"},
		    {"Search", "搜索"},
		    {"Level", "等级"},
		    {"Enable in MP", "在多人模式中启用"},
		    {"Name", "名称"},
		    {"Category", "类别"},
		    {"Categories", "类别"},
		    {"Locations", "位置"},
		    {"Distance", "距离"},
		    {"Saved", "已保存"},
		    {"Save", "保存"},
		    {"Load", "加载"},
		    {"Delete", "删除"},
		    {"Spawn Vehicle", "生成载具"},
		    {"Saved Vehicles", "已保存载具"},
		    {"Saved Players", "已保存玩家"},
		    {"Lua Scripts", "Lua脚本"},
		    {"God Mode", "无敌模式"},
		    {"Invisible", "隐身"},
		    {"No Clip", "穿墙"},
		    {"Free Cam", "自由视角"},
		    {"Super Run", "超级冲刺"},
		    {"Super Jump", "超级跳跃"},
		    {"Never Wanted", "永不通缉"},
		    {"Wanted Level", "通缉等级"},
		    {"Outfit Editor", "服装编辑器"},
		    {"Outfits", "服装"},
		    {"Weapons", "武器"},
		    {"Player", "玩家"},
		    {"Appearance", "外观"},
		    {"General", "常规"},
		    {"Display", "显示"},
		    {"Show", "显示"},
		    {"Hide", "隐藏"},
		    {"Default", "默认"},
		    {"Refresh", "刷新"},
		    {"Apply", "应用"},
		    {"Reset", "重置"},
		};

		if (auto it = translations.find(input); it != translations.end())
			return it->second;

		std::string lower = input;
		std::transform(lower.begin(), lower.end(), lower.begin(), [](unsigned char ch) {
			return static_cast<char>(std::tolower(ch));
		});

		if (auto it = translations.find(lower); it != translations.end())
			return it->second;

		return input;
	}

	// Function to trim leading and trailing whitespace from a string
	inline std::string TrimString(std::string& str)
	{
		auto start = str.begin();
		auto end = str.end();

		// Find the first non-whitespace character from the start
		while (start != end && std::isspace(*start))
		{
			++start;
		}

		// Find the last non-whitespace character from the end
		while (start != end && std::isspace(*(end - 1)))
		{
			--end;
		}

		return std::string(start, end);
	}

	inline std::string TrimString(char* str)
	{
		std::string t = str;
		return TrimString(t);
	}

	inline void StrCpySafe(char* dest, const char* src, int dest_size)
	{
		auto len = dest_size - 1;
		strncpy(dest, src, len);
		if (strlen(src) > len)
			dest[len] = '\0';
	}

	inline void ReplaceString(std::string& str, const char* str1, const char* str2)
	{
		size_t pos = 0;
		while ((pos = str.find(str1, pos)) != std::string::npos)
			str.replace(pos, strlen(str1), str2);
	}
}
