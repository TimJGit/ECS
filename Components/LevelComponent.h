#pragma once

class LevelComponent : public IComponent
{
public:
	LevelComponent() : m_Level(0) { }
	LevelComponent(int level) : m_Level(level) { }
	virtual ~LevelComponent() { }

	virtual ComponentID GetComponentID() const { return ComponentID::Level; }

	int GetLevel() const { return m_Level; }
	void SetLevel(int level) { m_Level = level; }

private:
	int m_Level;

	LevelComponent(const LevelComponent&) = delete;
	LevelComponent& operator=(const LevelComponent&) = delete;
};
