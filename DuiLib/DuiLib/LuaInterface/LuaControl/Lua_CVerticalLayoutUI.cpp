#include "LuaEntry.h"

#include REQUIRE_H(CVerticalLayoutUI)

namespace DuiLib
{
	LUA_METHOD_IMPL(CVerticalLayoutUI, New)
	{
		CVerticalLayoutUI  *ctrl = new CVerticalLayoutUI();
		LuaStatic::AddObject2Lua(l, ctrl, METATABLE_NAME(ctrl));
		return 1;
	}

	LUA_METHOD_IMPL(CVerticalLayoutUI, GetClassName)
	{
		CDuiString pstrText = CVerticalLayoutUI::GetClassName();
		lua_op_t<CDuiString>::push_stack(l, pstrText);
		return 1;
	}

	LUA_METHOD_IMPL(CVerticalLayoutUI,SetSepHeight)
	{
		try
		{
			CVerticalLayoutUI* self;
			self = static_cast<CVerticalLayoutUI*>(LuaStatic::CheckUserData(l, 1));
			int w = (int)lua_tointeger(l, 2);
			self->SetSepHeight(w);
			return 0;
		}
		catch (...)
		{
			DuiException(_T("LuaCVerticalLayoutUI::SetSepHeight"));
			return 0;
		}
	}

	LUA_METHOD_IMPL(CVerticalLayoutUI,GetSepHeight)
	{
		try
		{
			CVerticalLayoutUI* self;
			self = static_cast<CVerticalLayoutUI*>(LuaStatic::CheckUserData(l, 1));
			int w = self->GetSepHeight();
			lua_pushinteger(l,w);
			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCVerticalLayoutUI::GetSepHeight"));
			return 0;
		}
	}

	LUA_METHOD_IMPL(CVerticalLayoutUI,SetSepImmMode)
	{
		try
		{
			CVerticalLayoutUI* self;
			self = static_cast<CVerticalLayoutUI*>(LuaStatic::CheckUserData(l, 1));
			bool bAuto = lua_toboolean(l, 2) != 0;
			self->SetSepImmMode(bAuto);
			return 0;
		}
		catch (...)
		{
			DuiException(_T("LuaCVerticalLayoutUI::SetSepImmMode"));
			return 0;
		}
	}

	LUA_METHOD_IMPL(CVerticalLayoutUI,IsSepImmMode)
	{
		try
		{
			CVerticalLayoutUI* self;
			self = static_cast<CVerticalLayoutUI*>(LuaStatic::CheckUserData(l, 1));
			bool bRet = self->IsSepImmMode();
			lua_pushboolean(l, bRet ? 1 : 0);
			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCVerticalLayoutUI::IsSepImmMode"));
			return 0;
		}
	}	

	LUA_METHOD_IMPL(CVerticalLayoutUI,GetThumbRect)
	{
		try
		{
			CVerticalLayoutUI* self;
			self = static_cast<CVerticalLayoutUI*>(LuaStatic::CheckUserData(l, 1));
			bool bUseNew = false;
			if (!lua_isnone(l,2))
				bUseNew = lua_toboolean(l,2) != 0;
			RECT rt = self->GetThumbRect(bUseNew);

			LuaStatic::WriteRect2Lua(l, rt);
			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCVerticalLayoutUI::GetThumbRect"));
			return 0;
		}
	}


	LUA_CLASS_REG_IMPL(CVerticalLayoutUI)
	{
		lua_newtable(l);
		static LuaReg StaticFuncs[] =
		{
			{ "New", New },
			{ "GetClassName", GetClassName },
		};
		LuaStatic::LuaSetFuncsInTable(l, StaticFuncs, sizeof(StaticFuncs) / sizeof(StaticFuncs[0]));
		lua_setfield(l, -2, "VerticalLayoutUI");

		luaL_newmetatable(l, "CVerticalLayoutUI");
		luaL_getmetatable(l, "CContainerUI");
		lua_setmetatable(l, -2);
		
		lua_pushvalue(l, -1);
		lua_setfield(l, -2, "__index");
		static LuaReg MethodFuncs[] =
		{
			{ "SetSepHeight", SetSepHeight },
			{ "GetSepHeight", GetSepHeight },
			{ "SetSepImmMode", SetSepImmMode },
			{ "IsSepImmMode", IsSepImmMode },
			{ "GetThumbRect", GetThumbRect },
		};
		LuaStatic::LuaSetFuncsInTable(l, MethodFuncs, sizeof(MethodFuncs) / sizeof(MethodFuncs[0]));
		
		lua_pop(l, 1);
	}
}