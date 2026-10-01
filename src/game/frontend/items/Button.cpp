#include "Items.hpp"
#include "core/backend/FiberPool.hpp"

namespace YimMenu
{
	Button::Button(const std::string_view& name, std::function<void()> onClick, const ImVec2 size, const std::string_view& information) :
	    m_Name(LocalizeMenuText(std::string{name})),
	    m_Information(LocalizeMenuText(std::string{information})),
	    m_OnClick(onClick),
	    m_Size(size)
	{
	}

	void Button::Draw()
	{
		if (ImGui::Button(m_Name.data(), m_Size))
		{
			if (m_OnClick != nullptr)
			{
				FiberPool::Push([&] {
					m_OnClick();
				});
			}
		}
	}
}