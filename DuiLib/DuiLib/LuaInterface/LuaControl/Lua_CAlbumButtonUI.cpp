#include "LuaEntry.h"

#include REQUIRE_H(CAlbumButtonUI)

namespace DuiLib
{
	LUA_METHOD_IMPL(CAlbumButtonUI, New)
	{
		CAlbumButtonUI  *ctrl = new CAlbumButtonUI();
		LuaStatic::AddObject2Lua(l, ctrl, METATABLE_NAME(ctrl));
		return 1;
	}

	LUA_METHOD_IMPL(CAlbumButtonUI, GetClassName)
	{
		CDuiString pstrText = CAlbumButtonUI::GetClassName();
		lua_op_t<CDuiString>::push_stack(l, pstrText);
		return 1;
	}

	LUA_METHOD_IMPL(CAlbumButtonUI, SetHotBkImage)
	{
		try
		{
			CAlbumButtonUI* self;
			self = static_cast<CAlbumButtonUI*>(LuaStatic::CheckUserData(l, 1));
			CDuiString pstrText;
			lua_op_t<CDuiString>::lua_to_value(l, 2, pstrText);
			self->SetHotBkImage(pstrText);
			return 0;
		}
		catch (...)
		{
			DuiException(_T("LuaCAlbumButtonUI::SetHotBkImage"));
			return 0;
		}
	}

	LUA_METHOD_IMPL(CAlbumButtonUI, GetHotBkImage)
	{
		try
		{
			CAlbumButtonUI* self;
			self = static_cast<CAlbumButtonUI*>(LuaStatic::CheckUserData(l, 1));
			CDuiString pstrText = self->GetHotBkImage();

			lua_op_t<CDuiString>::push_stack(l, pstrText);
			return 1;
		}
		catch (...)
		{
			DuiException(_T("LuaCAlbumButtonUI::GetHotBkImage"));
			return 0;
		}
	}

	LUA_METHOD_IMPL(CAlbumButtonUI, SetAlbumImage)
	{
		try
		{
			CAlbumButtonUI* self;
			self = static_cast<CAlbumButtonUI*>(LuaStatic::CheckUserData(l, 1));
			CDuiString pstrText;
			lua_op_t<CDuiString>::lua_to_value(l, 2, pstrText);
			self->SetAlbumImage(pstrText);
			return 0;
		}
		catch (...)
		{
			DuiException(_T("LuaCAlbumButtonUI::SetAlbumImage"));
			return 0;
		}
	}
	
	LUA_CLASS_REG_IMPL(CAlbumButtonUI)
	{
		lua_newtable(l);
		static LuaReg StaticFuncs[] =
		{
			{ "New", New },
			{ "GetClassName", GetClassName },
		};
		LuaStatic::LuaSetFuncsInTable(l, StaticFuncs, sizeof(StaticFuncs) / sizeof(StaticFuncs[0]));
		lua_setfield(l, -2, "AlbumButtonUI");

		luaL_newmetatable(l, "CAlbumButtonUI");
		luaL_getmetatable(l, "CButtonUI");
		lua_setmetatable(l, -2);

		lua_pushvalue(l, -1);
		lua_setfield(l, -2, "__index");
		static LuaReg MethodFuncs[] =
		{
			{ "SetHotBkImage", SetHotBkImage },
			{ "GetHotBkImage", GetHotBkImage },
			{ "SetAlbumImage", SetAlbumImage },
		};
		LuaStatic::LuaSetFuncsInTable(l, MethodFuncs, sizeof(MethodFuncs) / sizeof(MethodFuncs[0]));

		lua_pop(l, 1);
	}
}