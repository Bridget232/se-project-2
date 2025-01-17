#pragma once
#include "Event.h"
#include "Defs.h"

namespace WEP
{	/**
	* @breif A Funeral event
	* 
	* A class that represents a funeral, with all its associated details.
	*/
	class Funeral : public Event
	{
	public:
		Funeral(String name, Date birth, Date death, Date date, List<Arc<Activity>> activites, List<Guest> guests, UUID businessId):
			deceasedName(name), birthDate(birth), deathDate(death), 
			Event(("Funeral for " + name + ": " + birth.toString() + " - " + death.toString()), date, activites, guests, businessId)
		{}

		/**
		*	@returns The deceased persons name
		*/
		const std::string& getDeceasedName() const { return this->deceasedName; }

		/**
		*	@returns The deceased persons birth date
		*/
		const Date& getBirthDate() const { return this->birthDate; }

		/**
		*	@returns The deceased persons deat date
		*/
		const Date& getDeathDate() const { return this->deathDate; }

		/**
		* @brief Implements the getDetails function from the Event class
		*/
		std::string getDetails() const override;

		/*
		* Promps the user to create a Funeral event, and fill out all the data for it
		* @param businessId The id for the owning business
		* @returns An invalid option if the creation was cancled, or a valid one if the creation was not
		*/
		static Option<Arc<Event>> promptCreateEvent(UUID businessId);
	private:
		std::string deceasedName;
		Date birthDate;
		Date deathDate;
	};
}