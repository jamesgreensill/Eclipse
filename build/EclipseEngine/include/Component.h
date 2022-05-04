#pragma once
#include "BaseModel.h"

namespace Eclipse
{
	class Object;

	namespace Components {
		
		/*
		 *
		 *	Forward declarations
		 *
		 */

		/// <summary>
		/// Component Class.
		/// The Component class is the base class for all behaviours.
		/// It allows for easy object creation and composition and follows the ECS paradigm
		/// </summary>
		class Component : public Engine::BaseModel
		{
			/**
			 * \brief Parent Object.
			 */

		public:
			friend class Eclipse::Object;
			bool enabled = true;
			/**
			 * \brief Returns the object this component is attached too.
			 * \return Parent Object.
			 */
			Object* object = nullptr;
		protected:
			~Component() override = default;

			void Dispose() override;
			void Update() override;
			void Draw() override;
			void LateUpdate() override;
			void FixedUpdate() override;
			void Awake() override;
			void RetrieveGuiData() override;
			void Start() override;
			void Deleted() override;
			void Created() override;

			virtual void Reset() = 0;


		};
	}
}
