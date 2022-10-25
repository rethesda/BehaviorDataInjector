#pragma once
#include "DKUtil/Config.hpp"
#include "nlohmann/json.hpp"

namespace BDI
{
	using json = nlohmann::json;

	struct BDIObject
	{
		friend void from_json(const json& j, BDIObject& a_data);
		friend class DataHandler;

		enum class DataTypes : std::uint32_t
		{
			kNone = 0,
			kBool = 1,
			kInt = 2,
			kFloat = 3,
			kEvent = 4
		};

	private:
		std::vector<std::string> projectNames;

		DataTypes type = DataTypes::kNone;

		std::string name;

		RE::hkbVariableValue value;
	};
	using BDIDataTypes = BDIObject::DataTypes;

	void from_json(const json& j, BDIObject& a_data);
}