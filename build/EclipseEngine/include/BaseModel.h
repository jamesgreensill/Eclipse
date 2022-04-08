#pragma once
#include <string>

#include <EclipseGui/include/ImGuiCall.h>

class BaseModel
{
public:
	virtual ~BaseModel() = default;

	/**
	 * \brief Replacement for constructor.
	 */
	virtual void Created() = 0;

	/**
	 * \brief Called before any frame.
	 */
	virtual void Awake();
	/**
	 * \brief Called on the first frame.
	 */
	virtual void Start();

	/**
 * \brief Called every frame
 */
	virtual void Update();
	/**
	 * \brief Called after Update.
	 */
	virtual void LateUpdate();
	/**
	 * \brief Called at a fixed rate.
	 */
	virtual void FixedUpdate();

	/**
	 * \brief Called at the start of rendering
	 */
	virtual void Draw();

	virtual void Gui();

	/**
	 * \brief Called on the last frame of this objects lifecycle.
	 */
	virtual void Dispose();

	/**
	 * \brief Replacement for destructor.
	 */
	virtual void Deleted() = 0;

	std::string name = "name not set.";
public:
	virtual void RetrieveGuiData(Eclipse::Engine::ImGuiTypes::ImGuiCall& call);
};
